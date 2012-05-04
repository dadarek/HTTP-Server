#include "gtest/gtest.h"
#include "ChartUrlParser.h"

class ChartUrlParserTests
  : public ::testing::Test
{
  public:
    ChartUrlParser parser;
};

TEST_F( ChartUrlParserTests, parsesOneLog )
{
  std::string opening_brace = "%7B";
  std::string closing_brace = "%7D";
  std::string quote = "%22";

  std::string date_ran = "2012-04-15";
  std::string time_ran = "30";

  std::string json = 
    "[" + 
    opening_brace + 
    quote + "date_ran" + quote + 
    ":" + 
    quote + date_ran + quote +
    quote + "time_ran" + quote + 
    ":" + 
    quote + time_ran + quote +
    closing_brace +
    "]";
  ASSERT_EQ(date_ran, parser.parseDate(json));
  ASSERT_EQ(time_ran, parser.parseTime(json));
}

TEST_F( ChartUrlParserTests, DecodesSingleCharacters )
{
  ASSERT_EQ("{", parser.urlDecode("%7B"));
  ASSERT_EQ("}", parser.urlDecode("%7D"));
  ASSERT_EQ("\"", parser.urlDecode("%22"));
}

TEST_F( ChartUrlParserTests, DecodesMultipleCharacters )
{
  std::string code("%7B%7D%7B%7B%22");
  ASSERT_EQ("{}{{\"", parser.urlDecode(code));
}

TEST_F( ChartUrlParserTests, DecodesMixedCodes )
{
  std::string code("%7B8%7Dt%7Bhlight%7B%22");
  ASSERT_EQ("{8}t{hlight{\"", parser.urlDecode(code));
}
