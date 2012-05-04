#include "gtest/gtest.h"
#include "ChartUrlParser.h"
#include "RunLog.h"

class ChartUrlParserTests
  : public ::testing::Test
{
  public:
    static std::string OPEN_BRACE;
    static std::string CLOSE_BRACE;
    static std::string QUOTE;
    ChartUrlParser parser;
};

std::string ChartUrlParserTests::OPEN_BRACE = "%7B";
std::string ChartUrlParserTests::CLOSE_BRACE = "%7D";
std::string ChartUrlParserTests::QUOTE= "%22";

TEST_F( ChartUrlParserTests, parsesOneLog )
{
  std::string date_ran = "2012-04-15";
  std::string time_ran = "30";

  std::string json = 
    "[" + 
    OPEN_BRACE + 
    QUOTE + "date_ran" + QUOTE + 
    ":" + 
    QUOTE + date_ran + QUOTE +
    QUOTE + "time_ran" + QUOTE + 
    ":" + 
    QUOTE + time_ran + QUOTE +
    CLOSE_BRACE +
    "]";

  const RunLog& log = parser.parse(json);

  ASSERT_EQ(date_ran, log.dateRan);
  ASSERT_EQ(time_ran, log.timeRan);
}

TEST_F( ChartUrlParserTests, Parses2Logs )
{
  std::string date_ran1 = "2012-04-15";
  std::string time_ran1 = "30";

  std::string date_ran2 = "2012-03-30";
  std::string time_ran2 = "15";

  std::string json = 
    "[" + 
    OPEN_BRACE + 
    QUOTE + "date_ran" + QUOTE + 
    ":" + 
    QUOTE + date_ran1 + QUOTE +
    QUOTE + "time_ran" + QUOTE + 
    ":" + 
    QUOTE + time_ran1 + QUOTE +
    CLOSE_BRACE +
    "," +
    OPEN_BRACE + 
    QUOTE + "date_ran" + QUOTE + 
    ":" + 
    QUOTE + date_ran2 + QUOTE +
    QUOTE + "time_ran" + QUOTE + 
    ":" + 
    QUOTE + time_ran2 + QUOTE +
    CLOSE_BRACE +
    "]";

}

TEST_F( ChartUrlParserTests, DecodesSingleCharacters )
{
  ASSERT_EQ("{", parser.urlDecode(OPEN_BRACE));
  ASSERT_EQ("}", parser.urlDecode(CLOSE_BRACE));
  ASSERT_EQ("\"", parser.urlDecode(QUOTE));
}

TEST_F( ChartUrlParserTests, DecodesMultipleCharacters )
{
  std::string code = OPEN_BRACE + CLOSE_BRACE + OPEN_BRACE + QUOTE;
  ASSERT_EQ("{}{\"", parser.urlDecode(code));
}

TEST_F( ChartUrlParserTests, DecodesMixedCodes )
{
  std::string code = OPEN_BRACE + "8" + CLOSE_BRACE + "t" + OPEN_BRACE + "hlight" + OPEN_BRACE + QUOTE;
  ASSERT_EQ("{8}t{hlight{\"", parser.urlDecode(code));
}
