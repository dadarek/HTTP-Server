#include "gtest/gtest.h"
#include "ChartUrlParser.h"
#include "RunLog.h"
#include "RunLogToJsonConverter.h"

TEST( ChartUrlParserTests, parsesOneLog )
{
  RunLog log;
  log.timeRan = 30;
  log.dateRan = Date(2012, 4, 15);

  std::string json = "[" + RunLogToJsonConverter::convert(log) + "]";

  ChartUrlParser parser;
  const std::vector<RunLog>& logs = parser.parse(json);

  ASSERT_EQ( log.dateRan, logs.back().dateRan );
  ASSERT_EQ( log.timeRan, logs.back().timeRan );
}

TEST( ChartUrlParserTests, Parses2Logs )
{
  RunLog log1;
  log1.timeRan = 30;
  log1.dateRan = Date( 2012, 4, 15 );

  RunLog log2;
  log2.timeRan = 15;
  log2.dateRan = Date( 2012, 3, 30 );

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
