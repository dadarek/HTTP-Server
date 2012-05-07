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
    std::vector<RunLog> logs_;

    ChartRequestHandlerTests()
    { }

    std::string getResponse()
    {
      const std::string& json = RunLogToJsonConverter::convert( logs_ );
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
  logs_.push_back( log );

  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99999]", getResponse().c_str() );
}

TEST_F( ChartRequestHandlerTests, Writes2WeekOf0sOnEmptyRequest)
{
  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]", getResponse().c_str() );
}

TEST_F( ChartRequestHandlerTests, WritesHistoricalLogsInCorrectPlace)
{
  Date today;
  Date yesterday; yesterday.addDays( -1 );
  Date twoDaysAgo; twoDaysAgo.addDays( -2 );

  RunLog log1( today, 30 );
  RunLog log2( twoDaysAgo, 45 );
  RunLog log3( yesterday, 33 );

  logs_.push_back( log1 );
  logs_.push_back( log2 );
  logs_.push_back( log3 );

  ASSERT_STREQ( "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 33, 30]", getResponse().c_str() );
}

TEST_F( ChartRequestHandlerTests, WritesFirstAndLastDateLogs)
{
  Date today;
  Date thirteenDaysAgo; thirteenDaysAgo.addDays( -13 );

  RunLog log1( today, 67 );
  RunLog log2( thirteenDaysAgo, 472 );

  logs_.push_back( log1 );
  logs_.push_back( log2 );

  ASSERT_STREQ( "[472, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 67]", getResponse().c_str() );
}



