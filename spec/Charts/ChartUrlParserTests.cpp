#include "gtest/gtest.h"
#include "ChartUrlParser.h"
#include "UrlUtilities.h"
#include "RunLog.h"

class ChartUrlParserTests
  : public ::testing::Test
{
  public:
    ChartUrlParser parser;

    std::string createLogJson(const Date& dateRan, int timeRan)
    {
      char json[100];
      sprintf( json, "{\"date_ran\":\"%d-%02d-%02d\",\"time_ran\":\"%d\"}", dateRan.year(), dateRan.month(), dateRan.day(), timeRan );

      return UrlUtilities::encode( json );
    }

    void assertLogEquals( const RunLog& log, const Date& dateRan, int timeRan )
    {
      ASSERT_EQ(dateRan, log.dateRan);
      ASSERT_EQ(timeRan, log.timeRan);
    }
};

TEST_F( ChartUrlParserTests, parsesOneLog )
{
  int timeRan = 30;
  Date dateRan( "2012-04-15" );

  std::string json = "[" + createLogJson( dateRan, timeRan ) + "]";

  const std::vector<RunLog>& logs = parser.parse(json);

  assertLogEquals( logs.back(), dateRan, timeRan );
}

TEST_F( ChartUrlParserTests, Parses2Logs )
{
  Date dateRan1( "2012-04-15" );
  int timeRan1 = 30;

  Date dateRan2( "2012-03-30" );
  int timeRan2 = 15;

  std::string json = 
    "[" + 
    createLogJson( dateRan1, timeRan1 ) +
    "," +
    createLogJson( dateRan2, timeRan2 ) +
    "]";

  const std::vector<RunLog>& logs = parser.parse(json);

  assertLogEquals( logs.front(), dateRan1, timeRan1 );
  assertLogEquals( logs.back(), dateRan2, timeRan2 );
}
