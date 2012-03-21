#include "gtest/gtest.h"
#include "mocks/MockSocket.h"
#include "InboundConnectionListener.h"

TEST( InboundConnectionListener, CreatesASocket ) {
  MockSocket* socket = new MockSocket();
  InboundConnectionListener listener( socket );

  EXPECT_TRUE( socket->socketsCreated_ == 1 );
}

TEST( InboundConnectionListener, BindsToTheSocketFDItReceives ) {
  MockSocket* socket = new MockSocket();
  InboundConnectionListener listener( socket );

  EXPECT_TRUE( socket->boundTo_ == socket->socketFD_ );
}

//TODO: Test error returns on:
//      - socket()
//      - bind( ... )
//      - accept( ... )

//TODO: Test proper parameters get sent to:
//      - bind()
//      - accept()
