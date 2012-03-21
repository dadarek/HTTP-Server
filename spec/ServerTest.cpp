#include "gtest/gtest.h"
#include "Server.h"
#include "mocks/MockRequestHandler.cpp"
#include "mocks/MockPortListener.cpp"

TEST( Server, PassesPortRequestsToHandler ) {
  int requestsToFake = 5;

  MockRequestHandler handler;
  MockPortListener listener( requestsToFake );
  Server server( &listener, &handler );
  
  server.start();

  EXPECT_EQ( requestsToFake, handler.requestsHandled() );
}

