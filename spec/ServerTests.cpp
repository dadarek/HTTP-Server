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

  receiver.returnValues_[ 0 ] = 1;

  Server server( receiver, handler );

  server.start();

  EXPECT_EQ( 1, handler.connectionsHandled_[ 0 ] );
}

TEST( ServerTests, ListensIndefinitely )
{
  MockRequestHandler handler;  
  MockConnectionReceiver receiver;

  receiver.returnValues_[ 0 ] = 3;
  receiver.returnValues_[ 1 ] = 8;
  receiver.returnValues_[ 2 ] = 158;
  receiver.returnValues_[ 3 ] = 1025;

  Server server( receiver, handler );

  server.start();

  EXPECT_EQ( 3, handler.connectionsHandled_[ 0 ] );

}

