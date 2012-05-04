#include "gtest/gtest.h"
#include "ChartRequestHandlerFactory.h"
#include "HttpRequest.h"

class ChartRequestHandlerFactoryTests
  : public ::testing::Test
{
  public:
    ChartRequestHandlerFactoryTests()
    { }
};

TEST_F( ChartRequestHandlerFactoryTests, compiles )
{
  int i = 0;
  i++;
}
