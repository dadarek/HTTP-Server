#include "gtest/gtest.h"
#include "ChartUrlParser.h"

TEST( ChartUrlParserTests, parsesOneLog )
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
  ChartUrlParser parser;
  ASSERT_EQ(date_ran, parser.parseDate(json));
  ASSERT_EQ(time_ran, parser.parseTime(json));
}

TEST( ChartUrlParserTests, DecodesUrlEncoding )
{
  ChartUrlParser parser;
  ASSERT_EQ("{", parser.urlDecode("%7B"));
  ASSERT_EQ("}", parser.urlDecode("%7D"));
  ASSERT_EQ("\"", parser.urlDecode("%22"));
}
