#include "gtest/gtest.h"
#include "HttpConnectionHandler.h"
#include "HttpConnectionHandlerInspector.h"
#include "MockSocketReader.h"
#include "MockHttpRequestParser.h"
#include "MockHttpRequestHandler.h"
#include "MockHttpRequestHandlerFactory.h"
#include "MockHttpRequest.h"
#include "MockHttpResponse.h"
#include "MockHttpResponseWriter.h"

class HttpConnectionHandlerTester
  : public ::testing::Test
{
  public:
    static const int SOCKET_TO_HANDLE;

    HttpConnectionHandlerInspector inspector_;

    MockSocketReader socketReader_;
    MockHttpRequestParser parser_;
    MockHttpRequestHandlerFactory factory_;
    MockHttpResponseWriter writer_;

    MockHttpRequest* request_;
    MockHttpResponse* response_;
    MockHttpRequestHandler* requestHandler_;

    HttpConnectionHandler connectionHandler_;

    HttpConnectionHandlerTester()
      : inspector_()
      , socketReader_()
      , parser_()
      , factory_()
      , writer_( inspector_ )
      , request_( new MockHttpRequest( inspector_ ) )
      , response_( new MockHttpResponse( inspector_ ) ) 
      , requestHandler_( new MockHttpRequestHandler( inspector_ ) )
      , connectionHandler_( socketReader_, parser_, factory_, writer_ )
    { 
      parser_.parseReturnValue_ = request_;
      requestHandler_->handleReturnValue_ = response_;
      factory_.createHandlerReturnValue_ = requestHandler_;
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
  ASSERT_EQ( request_, requestHandler_->requestReceived_ );
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

TEST_F( HttpConnectionHandlerTester, deletesHandler )
{
  handleSomething();
  ASSERT_EQ( true, inspector_.handlerDestroyed );
}

TEST_F( HttpConnectionHandlerTester, forwardsResponseToResponseWriter )
{
  handleSomething();
  ASSERT_EQ( response_, writer_.responseReceived_ );
}

