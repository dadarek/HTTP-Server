#include "gtest/gtest.h"
#include "ChartUrlParser.h"
#include "RunLog.h"
#include "RunLogToJsonConverter.h"

TEST( ChartUrlParserTests, parsesOneLog )
{
  RunLog log( "2012-04-15", 30 );

  std::string json = "[" + RunLogToJsonConverter::convert(log) + "]";

  ChartUrlParser parser;
  const std::vector<RunLog>& logs = parser.parse(json);

  ASSERT_EQ( log.dateRan, logs.back().dateRan );
  ASSERT_EQ( log.timeRan, logs.back().timeRan );
}

TEST( ChartUrlParserTests, Parses2Logs )
{
  RunLog log1( "2012-04-15", 30 );
  RunLog log2( "2012-03-30", 15 );

  std::string json = 
    "[" + 
    RunLogToJsonConverter::convert( log1 ) +
    "," +
    RunLogToJsonConverter::convert( log2 ) +
    "]";

  ChartUrlParser parser;
  const std::vector<RunLog>& logs = parser.parse(json);

  ASSERT_EQ( log1.dateRan, logs.front().dateRan );
  ASSERT_EQ( log1.timeRan, logs.front().timeRan );

  ASSERT_EQ( log2.dateRan, logs.back().dateRan );
  ASSERT_EQ( log2.timeRan, logs.back().timeRan );
}
