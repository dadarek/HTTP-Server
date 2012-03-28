#include "gtest/gtest.h"
#include "HttpConnectionHandler.h"
#include "HttpConnectionHandlerInspector.h"
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
    static const int SOCKET_TO_HANDLE;

    MockSocketReader socketReader_;
    MockHttpRequestParser parser_;
    MockHttpRequestHandler requestHandler_;
    MockHttpRequestHandlerFactory factory_;
    HttpConnectionHandler connectionHandler_;

    HttpConnectionHandlerInspector inspector_;
    MockHttpRequest* request_;
    MockHttpResponse* response_;

    HttpConnectionHandlerTester()
      : socketReader_()
      , parser_()
      , requestHandler_()
      , factory_()
      , connectionHandler_( socketReader_, parser_, factory_ )
      , request_( new MockHttpRequest( inspector_ ) )
      , response_( new MockHttpResponse( inspector_ ) ) 
    { 
      parser_.parseReturnValue_ = request_;
      requestHandler_.handleReturnValue_ = response_;
      factory_.createHandlerReturnValue_ = &requestHandler_;
    }

    void handleSomething()
    {
      connectionHandler_.handle( HttpConnectionHandlerTester::SOCKET_TO_HANDLE );
    }
};

const int HttpConnectionHandlerTester::SOCKET_TO_HANDLE = 5;

TEST_F( HttpConnectionHandlerTester, readsToEnd )
{
  handleSomething();
  ASSERT_EQ( true, socketReader_.readToEnd_ );
}

TEST_F( HttpConnectionHandlerTester, readsOnSocketItReceives )
{
  handleSomething();
  ASSERT_EQ( HttpConnectionHandlerTester::SOCKET_TO_HANDLE, socketReader_.socketFDRead_ );
}

TEST_F( HttpConnectionHandlerTester, forwardsSocketDataToParser )
{
  socketReader_.readToEndReturnValue_ = "Hi there";
  handleSomething();
  ASSERT_STREQ( "Hi there", parser_.stringToParse_.c_str() );
}

TEST_F( HttpConnectionHandlerTester, forwardsParserDataToFactory )
{
  handleSomething();
  ASSERT_EQ( request_, factory_.requestReceived_ );
}

TEST_F( HttpConnectionHandlerTester, forwardsRequestToHandlerFromFactory )
{
  handleSomething();
  ASSERT_EQ( request_, requestHandler_.requestReceived_ );
}

TEST_F( HttpConnectionHandlerTester, deletesRequest )
{
  handleSomething();
  ASSERT_EQ( true, inspector_.requestDestroyed );
}

TEST_F( HttpConnectionHandlerTester, deletesResponses )
{
  handleSomething();
  ASSERT_EQ( true, inspector_.responseDestroyed );
}

// make sure it deletes response after writing
// make sure it deletes the HttpHandler
// HttpConnectionHandler takes a SocketReader AND a SocketAPI? I don't like that ...
// rename handler_ to connectionHandler_
