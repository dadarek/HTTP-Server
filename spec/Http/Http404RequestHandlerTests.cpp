#include "gtest/gtest.h"
#include "Http404RequestHandler.h"

class Http404RequestHandlerTests
  : public ::testing::Test
{
  public:

};

TEST_F( Http404RequestHandlerTests, Compiles )
{
  Http404RequestHandler handler;
}
