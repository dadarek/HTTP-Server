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

    std::string urlEncode( const char* value )
    {
      std::string result;

      for( size_t i = 0; i < strlen(value); i++ )
      {
        switch( value[i] )
        {
          case '{':
            result += OPEN_BRACE;
            break;
          case '}':
            result += CLOSE_BRACE;
            break;
          case '"':
            result += QUOTE;
            break;
          default:
            result += value[i];
            break;
        }
      }

      return result;
    }
    std::string createLogJson(const char* dateRan, int timeRan)
    {
      char json[100];
      memset( json, 0, 100 );

      sprintf( json, "{\"date_ran\":\"%s\",\"time_ran\":\"%d\"}", dateRan, timeRan );

      return urlEncode( json );
    }
};

std::string ChartUrlParserTests::OPEN_BRACE = "%7B";
std::string ChartUrlParserTests::CLOSE_BRACE = "%7D";
std::string ChartUrlParserTests::QUOTE= "%22";

TEST_F( ChartUrlParserTests, parsesOneLog )
{
  const char* dateRan = "2012-04-15";
  int timeRan = 30;

  std::string json = "[" + createLogJson( dateRan, timeRan ) + "]";

  const std::vector<RunLog>& logs = parser.parse(json);

  ASSERT_STREQ(dateRan, logs.back().dateRan.c_str());
  ASSERT_EQ(timeRan, logs.back().timeRan);
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

  ASSERT_STREQ(dateRan1, logs.front().dateRan.c_str());
  ASSERT_EQ(timeRan1, logs.front().timeRan);

  ASSERT_STREQ(dateRan2, logs.back().dateRan.c_str());
  ASSERT_EQ(timeRan2, logs.back().timeRan);

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
