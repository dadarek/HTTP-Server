#include "gtest/gtest.h"
#include "Server.h"
#include "mocks/MockRequestHandler.cpp"

TEST(Server, ListensToPortAndHandsOffToHandler) {
  MockRequestHandler handler;
  Server server( &handler );
  
  server.start();

  EXPECT_EQ( handler.requestsHandled(), 1 );
}
