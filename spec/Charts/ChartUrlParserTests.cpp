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
  std::string dateRan = "2012-04-15";
  std::string timeRan = "30";

  std::string json = 
    "[" + 
    OPEN_BRACE + 
    QUOTE + "date_ran" + QUOTE + 
    ":" + 
    QUOTE + dateRan + QUOTE +
    QUOTE + "time_ran" + QUOTE + 
    ":" + 
    QUOTE + timeRan + QUOTE +
    CLOSE_BRACE +
    "]";

  const std::vector<RunLog>& logs = parser.parse(json);

  ASSERT_EQ(dateRan, logs.back().dateRan);
  ASSERT_EQ(timeRan, logs.back().timeRan);
}

TEST_F( ChartUrlParserTests, Parses2Logs )
{
  std::string dateRan1 = "2012-04-15";
  std::string timeRan1 = "30";

  std::string dateRan2 = "2012-03-30";
  std::string timeRan2 = "15";

  std::string json = 
    "[" + 
    OPEN_BRACE + 
    QUOTE + "date_ran" + QUOTE + 
    ":" + 
    QUOTE + dateRan1 + QUOTE +
    QUOTE + "time_ran" + QUOTE + 
    ":" + 
    QUOTE + timeRan1 + QUOTE +
    CLOSE_BRACE +
    "," +
    OPEN_BRACE + 
    QUOTE + "date_ran" + QUOTE + 
    ":" + 
    QUOTE + dateRan2 + QUOTE +
    QUOTE + "time_ran" + QUOTE + 
    ":" + 
    QUOTE + timeRan2 + QUOTE +
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
