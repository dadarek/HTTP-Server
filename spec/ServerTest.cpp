#include "gtest/gtest.h"
#include "Server.h"

TEST(ServerTest, Starts) {
  Server server;
  server.start();

  EXPECT_TRUE(server.isStarted());
}

TEST(ServerTest, Stops) {
  Server server;
  server.stop();

  EXPECT_FALSE(server.isStarted());
}

