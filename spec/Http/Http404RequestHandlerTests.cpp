#include "gtest/gtest.h"
#include "Http404RequestHandler.h"
#include <string>

class Http404RequestHandlerTests
  : public ::testing::Test
{
  public:

};

TEST_F( Http404RequestHandlerTests, 404TextContainsNotFound)
{
  std::string message( Http404RequestHandler::HTML_404 );
  std::string expectedTest( "Page Not Found");
  
  ASSERT_NE( std::string::npos, message.find( expectedTest ) );
}
