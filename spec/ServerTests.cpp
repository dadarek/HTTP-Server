#include "gtest/gtest.h"
#include "Server.h"
#include "mocks/MockRequestHandler.h"
#include "mocks/MockInboundConnectionListener.h"

class ServerTests
  : public testing::Test
{

};

TEST( ServerTests, PassesPortRequestsToHandler ) 
{
  MockRequestHandler handler;  

}

