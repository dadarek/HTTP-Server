#include "gtest/gtest.h"
#include "HttpConnectionHandler.h"
#include "MockSocketReader.h"
#include "MockHttpRequestParser.h"
#include "MockHttpRequestHandler.h"
#include "MockHttpRequestHandlerFactory.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpConnectionHandlerTester
  : public ::testing::Test
{
  public:
      MockSocketReader socketReader_;
      MockHttpRequestParser parser_;
      MockHttpRequestHandler requestHandler_;
      MockHttpRequestHandlerFactory factory_;
      HttpConnectionHandler handler_;
      HttpRequest request_;

    HttpConnectionHandlerTester()
      : socketReader_()
      , parser_()
      , requestHandler_()
      , factory_()
      , handler_( socketReader_, parser_, factory_ )
      , request_( "Some Request" )
    { 
      parser_.parseReturnValue_ = &request_;
      factory_.createHandlerReturnValue_ = &requestHandler_;
    }
};

TEST_F( HttpConnectionHandlerTester, readsToEnd )
{
  handler_.handle( 5 );
  ASSERT_EQ( true, socketReader_.readToEnd_ );
}

TEST_F( HttpConnectionHandlerTester, readsOnSocketItReceives )
{
  handler_.handle( 8 );
  ASSERT_EQ( 8, socketReader_.socketFDRead_ );
}

TEST_F( HttpConnectionHandlerTester, forwardsSocketDataToParser )
{
  socketReader_.readToEndReturnValue_ = "Hi there";
  handler_.handle( 8 );
  ASSERT_STREQ( "Hi there", parser_.stringToParse_.c_str() );
}

TEST_F( HttpConnectionHandlerTester, forwardsParserDataToFactory )
{
  handler_.handle( 8 );
  ASSERT_EQ( &request_, factory_.requestReceived_ );
}

TEST_F( HttpConnectionHandlerTester, forwardsRequestToHandlerFromFactory )
{
  handler_.handle( 8 );
  ASSERT_EQ( &request_, requestHandler_.requestReceived_ );
}

// make sure it deletes the request and response
// make sure it deletes response after writing
// make sure it deletes the HttpHandler
// HttpConnectionHandler takes a SocketReader AND a SocketAPI? I don't like that ...
