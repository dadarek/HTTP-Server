#include "gtest/gtest.h"
#include "HttpConnectionHandler.h"
#include "MockSocketReader.h"
#include "MockHttpRequestParser.h"
#include "MockHttpRequestHandlerFactory.h"

class HttpConnectionHandlerTester
  : public ::testing::Test
{
  public:
      MockSocketReader socketReader_;
      MockHttpRequestParser parser_;
      MockHttpRequestHandlerFactory factory_;
      HttpConnectionHandler handler_;

    HttpConnectionHandlerTester()
      : socketReader_()
      , parser_()
      , factory_()
      , handler_( socketReader_, parser_, factory_ )
    { }
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

