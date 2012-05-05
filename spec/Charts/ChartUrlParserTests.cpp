#include "gtest/gtest.h"
#include "ChartUrlParser.h"
#include "UrlUtilities.h"
#include "RunLog.h"

class ChartUrlParserTests
  : public ::testing::Test
{
  public:
    ChartUrlParser parser;

    std::string createLogJson(const char* dateRan, int timeRan)
    {
      char json[100];
      memset( json, 0, 100 );

      sprintf( json, "{\"date_ran\":\"%s\",\"time_ran\":\"%d\"}", dateRan, timeRan );

      return UrlUtilities::encode( json );
    }

    void assertLogEquals( const RunLog& log, const char* dateRan, int timeRan )
    {
      ASSERT_STREQ(dateRan, log.dateRan.c_str());
      ASSERT_EQ(timeRan, log.timeRan);
    }
};

TEST_F( ChartUrlParserTests, parsesOneLog )
{
  const char* dateRan = "2012-04-15";
  int timeRan = 30;

  std::string json = "[" + createLogJson( dateRan, timeRan ) + "]";

  const std::vector<RunLog>& logs = parser.parse(json);

  assertLogEquals( logs.back(), dateRan, timeRan );
}

TEST_F( ChartUrlParserTests, Parses2Logs )
{
  const char* dateRan1 = "2012-04-15";
  int timeRan1 = 30;

  const char* dateRan2 = "2012-03-30";
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
