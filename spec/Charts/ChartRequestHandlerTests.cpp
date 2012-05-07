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

    std::string getResponse( const std::vector<RunLog> logs )
    {
      const std::string& json = RunLogToJsonConverter::convert( logs );
      HttpRequest request( "", json.c_str() );

      HttpResponse* response = handler_.handle( request );

      char body[1024];
      memset( body, 0, 1024 );
      memcpy( body, response->body(), response->bodyLength() );

      return std::string(body);
    }
};

TEST_F( ChartRequestHandlerTests, Sets200Status )
{
  HttpRequest request( "", "" );

  HttpResponse* response = handler_.handle( request );
  ASSERT_STREQ( "200 OK", response->status().c_str() );
}

TEST_F( ChartRequestHandlerTests, IncludesRunLogTimeInJavascriptArray )
{
  RunLog log( Date(), 99999 );
  std::vector<RunLog> logs;
  logs.push_back( log );

  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99999]", getResponse(logs).c_str() );
}

TEST_F( ChartRequestHandlerTests, Writes2WeekOf0sOnEmptyRequest)
{
  std::vector<RunLog> logs;
  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]", getResponse(logs).c_str() );
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

  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 33, 30]", getResponse(logs).c_str() );
}

TEST_F( ChartRequestHandlerTests, WritesFirstAndLastDateLogs)
{
  Date today;
  Date thirteenDaysAgo; thirteenDaysAgo.addDays( -13 );

  RunLog log1( today, 67 );
  RunLog log2( thirteenDaysAgo, 472 );

  std::vector<RunLog> logs;
  logs.push_back( log1 );
  logs.push_back( log2 );

  ASSERT_STREQ( "[472, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 67]", getResponse(logs).c_str() );
}



