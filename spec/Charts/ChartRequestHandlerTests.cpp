#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "ChartRequestHandler.h"
#include "RunLog.h"
#include "RunLogToJsonConverter.h"

class ChartRequestHandlerTests
  : public ::testing::Test
{
  public:
    ChartRequestHandler handler_;

    ChartRequestHandlerTests()
    { }
};

TEST_F( ChartRequestHandlerTests, Sets200Status )
{
  HttpRequest request( "", "" );

  HttpResponse* response = handler_.handle( request );
  ASSERT_STREQ( "200 OK", response->status().c_str() );
}

TEST_F( ChartRequestHandlerTests, IncludesRunLogTimeInJavascriptArray )
{
  Date today;
  RunLog log( today, 99999 );

  const std::string& json = RunLogToJsonConverter::convert( log );
  HttpRequest request( "", json.c_str() );

  HttpResponse* response = handler_.handle( request );

  ASSERT_NE( (char*) 0, strstr(response->body(), "[99999]" ));
}

TEST_F( ChartRequestHandlerTests, Writes2WeekOf0sOnEmptyRequest)
{
  HttpRequest request( "", "" );
  HttpResponse* response = handler_.handle( request );

  ASSERT_NE( (char*) 0, strstr(response->body(), "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]" ));
}

