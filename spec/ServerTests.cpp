#include "gtest/gtest.h"
#include "Server.h"
#include "mocks/MockRequestHandler.h"
#include "mocks/MockConnectionReceiver.h"

class ServerTests
  : public testing::Test
{

};

TEST( ServerTests, ListensIndefinitely )
{
  MockRequestHandler handler;  
  MockConnectionReceiver receiver;

  receiver.returnValues_[ 0 ] = 3;
  receiver.returnValues_[ 1 ] = 8;
  receiver.returnValues_[ 2 ] = 158;
  receiver.returnValues_[ 3 ] = 1025;

  Server server( receiver, handler );

  EXPECT_THROW( server.start(), TerminationException );

  EXPECT_EQ( 3, handler.connectionsHandled_[ 0 ] );
  EXPECT_EQ( 8, handler.connectionsHandled_[ 1 ] );
  EXPECT_EQ( 158, handler.connectionsHandled_[ 2 ] );
  EXPECT_EQ( 1025, handler.connectionsHandled_[ 3 ] );
}

