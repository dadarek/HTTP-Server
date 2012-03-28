#include "gtest/gtest.h"
#include "HttpConnectionHandler.h"
#include "MockSocketReader.h"
#include "MockHttpRequestParser.h"
#include "MockHttpRequestHandler.h"
#include "MockHttpRequestHandlerFactory.h"
#include "MockHttpRequest.h"
#include "MockHttpResponse.h"

class HttpConnectionHandlerTester
  : public ::testing::Test
{
  public:
      MockSocketReader socketReader_;
      MockHttpRequestParser parser_;
      MockHttpRequestHandler requestHandler_;
      MockHttpRequestHandlerFactory factory_;
      HttpConnectionHandler handler_;

      HttpRequestInspector requestInspector_;
      HttpResponseInspector responseInspector_;
      MockHttpRequest* request_;
      MockHttpResponse* response_;

    HttpConnectionHandlerTester()
      : socketReader_()
      , parser_()
      , requestHandler_()
      , factory_()
      , handler_( socketReader_, parser_, factory_ )
      , requestInspector_()
      , responseInspector_()
      , request_( new MockHttpRequest( requestInspector_ ) )
      , response_( new MockHttpResponse( responseInspector_ ) ) 
    { 
      parser_.parseReturnValue_ = request_;
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
  ASSERT_EQ( request_, factory_.requestReceived_ );
}

TEST_F( HttpConnectionHandlerTester, forwardsRequestToHandlerFromFactory )
{
  handler_.handle( 8 );
  ASSERT_EQ( request_, requestHandler_.requestReceived_ );
}

TEST_F( HttpConnectionHandlerTester, deletesRequest )
{
  handler_.handle( 8 );
  ASSERT_EQ( true, requestInspector_.destroyed );
}

// make sure it deletes the request and response
// make sure it deletes response after writing
// make sure it deletes the HttpHandler
// HttpConnectionHandler takes a SocketReader AND a SocketAPI? I don't like that ...
