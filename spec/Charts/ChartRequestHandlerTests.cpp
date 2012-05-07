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

  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99999]", response->body() );
}

TEST_F( ChartRequestHandlerTests, Writes2WeekOf0sOnEmptyRequest)
{
  HttpRequest request( "", "" );
  HttpResponse* response = handler_.handle( request );

  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]", response->body() );
}

TEST_F( ChartRequestHandlerTests, WritesHistoricalLogsInCorrectPlace)
{
  Date today;
  Date yesterday; yesterday.addDays( -1 );
  Date twoDaysAgo; twoDaysAgo.addDays( -2 );

  RunLog log1( today, 30 );
  RunLog log2( twoDaysAgo, 45 );
  RunLog log3( yesterday, 33 );

  std::vector<RunLog> logs;
  logs.push_back( log1 );
  logs.push_back( log2 );
  logs.push_back( log3 );

  const std::string& json = RunLogToJsonConverter::convert( logs );
  HttpRequest request( "", json.c_str() );

  HttpResponse* response = handler_.handle( request );

  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 33, 30]", response->body() );
}

