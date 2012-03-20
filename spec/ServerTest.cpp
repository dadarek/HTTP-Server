#include "gtest/gtest.h"
#include "Server.h"

TEST(Server, Starts) {
  Server server;
  server.start();

  EXPECT_TRUE(server.isStarted());
}

TEST(Server, Stops) {
  Server server;
  server.stop();

  EXPECT_FALSE(server.isStarted());
}

