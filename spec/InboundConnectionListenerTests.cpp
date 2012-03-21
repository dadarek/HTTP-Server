#include "gtest/gtest.h"
#include "mocks/MockSocket.h"
#include "InboundConnectionListener.h"

TEST( InboundConnectionListener, CreatesASocket ) {
  MockSocket* socket = new MockSocket();
  InboundConnectionListener listener( socket );

  EXPECT_TRUE( socket->socketsCreated == 1 );
}

