#include "gtest/gtest.h"
#include "mocks/MockSocketApi.h"
#include "SocketConnectionReceiver.h"

class SocketConnectionReceiverTester
  : public ::testing::Test
{
  protected:
    const int PORT_TO_BIND_TO;

    struct MockSocketApiReturnValues returnValues_;
    struct MockSocketApiInputValues inputValues_;
    struct MockSocketApiFlags flags_;

    MockSocketApi socketApi_;

    SocketConnectionReceiver* createReceiver()
    {
      return new SocketConnectionReceiver( socketApi_, PORT_TO_BIND_TO ); 
    }

    void createAndDeleteReceiver()
    {
      delete createReceiver();
    }

  public:
    SocketConnectionReceiverTester()
      : PORT_TO_BIND_TO( 8090 )
      , returnValues_( 85, 0, 7777 )
      , socketApi_( returnValues_, inputValues_, flags_ )
    { }
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
  catch( int )
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
  ASSERT_THROW( createAndDeleteReceiver(), int );
}

TEST_F( SocketConnectionReceiverTester, DestructorClosesFD )  
{
  {
    createAndDeleteReceiver();
  }
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( SocketConnectionReceiverTester, ListensToSocketFDItReceives )  
{
  createAndDeleteReceiver();
  EXPECT_EQ( returnValues_.socket, inputValues_.listen );
}

TEST_F( SocketConnectionReceiverTester, AcceptsConnectionsOnSocketFDItReceives )  
{
  SocketConnectionReceiver* receiver = createReceiver();
  receiver->nextConnection();

  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
  delete receiver;
}

TEST_F( SocketConnectionReceiverTester, PassesInCorrectSocketFDToAccept )  
{
  SocketConnectionReceiver* receiver = createReceiver();
  receiver->nextConnection();

  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
  delete receiver;
}

TEST_F( SocketConnectionReceiverTester, ThrowsExceptionWhenAcceptFails )  
{
  SocketConnectionReceiver* receiver = createReceiver();
  flags_.acceptShouldError = true;

  ASSERT_THROW( receiver->nextConnection(), int );
  delete receiver;
}

TEST_F( SocketConnectionReceiverTester, NextConnectionReturnsCorrectFD )  
{
  SocketConnectionReceiver* receiver = createReceiver();
  int actual = receiver->nextConnection(); 

  ASSERT_EQ( returnValues_.accept, actual );
  delete receiver;
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

//
// Get rid of address stuff from RawSocketApi
// Does not crash when you comment out INADDR_ANY
// Does not crash when you comment out bzero
// Check the sizevalue input into bind
// If you comment out fd_ = -1 in SocketConnectionReceiver, no tests crash.
// Maybe we can get rid of the memset( 0 )?
// Refactor SocketConnectionReceiver (extract method)
