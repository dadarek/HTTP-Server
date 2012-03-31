#include "gtest/gtest.h"
#include "mocks/MockSocketApi.h"
#include "SocketConnectionReceiver.h"
#include "SocketBindException.h"

class SocketConnectionReceiverTester
  : public ::testing::Test
{
  protected:
    const int PORT_TO_BIND_TO;

    struct MockSocketApiReturnValues returnValues_;
    struct MockSocketApiInputValues inputValues_;
    struct MockSocketApiFlags flags_;

    MockSocketApi socketApi_;

    SocketConnectionReceiverTester()
      : PORT_TO_BIND_TO( 8090 )
      , returnValues_( 85, 0, 7777 )
      , socketApi_( returnValues_, inputValues_, flags_ )
    { }

    SocketConnectionReceiver* createReceiver()
    {
      return new SocketConnectionReceiver( socketApi_, PORT_TO_BIND_TO ); 
    }

    void createAndDeleteReceiver()
    {
      delete createReceiver();
    }

    int callNextConnection()
    {
      SocketConnectionReceiver* receiver = createReceiver();
      int result = receiver->nextConnection();
      delete receiver;

      return result;
    }
};


TEST_F( SocketConnectionReceiverTester, CreatesASocket )
{
  createAndDeleteReceiver();
  ASSERT_TRUE( flags_.socketCalled );
}

TEST_F( SocketConnectionReceiverTester, ThrowsExceptionOnErrorSocket ) 
{
  flags_.socketShouldError = true;
  ASSERT_THROW( createAndDeleteReceiver(), int );
}

TEST_F( SocketConnectionReceiverTester, ClosesFDOnBindException ) 
{
  flags_.bindShouldError = true;
  try
  {
    createAndDeleteReceiver();
  }
  catch( SocketBindException )
  { }
  
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( SocketConnectionReceiverTester, BindsToSocketFDItReceives ) 
{
  createAndDeleteReceiver();
  EXPECT_EQ( returnValues_.socket, inputValues_.bindFD );
}

TEST_F( SocketConnectionReceiverTester, ThrowsExceptionOnErrorBind )  
{
  flags_.bindShouldError = true;
  ASSERT_THROW( createAndDeleteReceiver(), SocketBindException );
}

TEST_F( SocketConnectionReceiverTester, DestructorClosesFD )  
{
  createAndDeleteReceiver();
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( SocketConnectionReceiverTester, ListensToSocketFDItReceives )  
{
  createAndDeleteReceiver();
  EXPECT_EQ( returnValues_.socket, inputValues_.listen );
}

TEST_F( SocketConnectionReceiverTester, PassesInCorrectSocketFDToAccept )  
{
  callNextConnection();
  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
}

TEST_F( SocketConnectionReceiverTester, ThrowsExceptionWhenAcceptFails )  
{
  flags_.acceptShouldError = true;
  ASSERT_THROW( callNextConnection(), int );
}

TEST_F( SocketConnectionReceiverTester, NextConnectionReturnsCorrectFD )  
{
  int actual = callNextConnection();
  ASSERT_EQ( returnValues_.accept, actual );
}

TEST_F( SocketConnectionReceiverTester, PassesInCorrectParametersToBind )
{
  struct sockaddr_in expectedAddress;
  size_t addressSize = sizeof( expectedAddress );
  memset( &expectedAddress, 0, addressSize );
  expectedAddress.sin_family = AF_INET;
  expectedAddress.sin_addr.s_addr = INADDR_ANY;
  expectedAddress.sin_port = htons( PORT_TO_BIND_TO );

  createAndDeleteReceiver();
  
  int difference = memcmp( &expectedAddress, &(inputValues_.bindAddress), addressSize );

  ASSERT_EQ( 0, difference );
}

TEST_F( SocketConnectionReceiverTester, PassesInCorrectSizeToAccept )
{
  SocketConnectionReceiver* receiver = createReceiver();
  receiver->nextConnection(); 
  delete receiver;

  struct sockaddr_in someAddress;
  socklen_t someAddressSize = sizeof( someAddress );
  EXPECT_EQ( someAddressSize, inputValues_.acceptSockAddressSize );
}
