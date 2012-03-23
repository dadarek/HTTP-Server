#include "gtest/gtest.h"
#include "Server.h"
#include "mocks/MockRequestHandler.h"
#include "mocks/MockConnectionReceiver.h"

class ServerTests
  : public testing::Test
{

};

TEST( ServerTests, PassesPortRequestsToHandler ) 
{
  MockRequestHandler handler;  
  MockConnectionReceiver receiver;

  Server server( receiver, handler );

  server.start();

  EXPECT_EQ( 1, handler.connectionHandled_ );

}

