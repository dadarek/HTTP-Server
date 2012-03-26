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

    SocketConnectionReceiver* createListener()
    {
      return new SocketConnectionReceiver( &socketApi_, PORT_TO_BIND_TO ); 
    }

    void createAndDeleteListener()
    {
      delete createListener();
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
  createAndDeleteListener();
  ASSERT_TRUE( flags_.socketCalled );
}

TEST_F( SocketConnectionReceiverTester, ThrowsExceptionOnErrorSocket ) 
{
  flags_.socketShouldError = true;
  ASSERT_THROW( createAndDeleteListener(), int );
}

TEST_F( SocketConnectionReceiverTester, ClosesFDOnBindException ) 
{
  flags_.bindShouldError = true;
  try
  {
    createAndDeleteListener();
  }
  catch( int )
  { }
  
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( SocketConnectionReceiverTester, BindsToSocketFDItReceives ) 
{
  createAndDeleteListener();
  EXPECT_EQ( returnValues_.socket, inputValues_.bindFD );
}

TEST_F( SocketConnectionReceiverTester, BindsToPortSpecifiedInConstructor ) 
{
  createAndDeleteListener();
  EXPECT_EQ( PORT_TO_BIND_TO, inputValues_.bindPort );
}

TEST_F( SocketConnectionReceiverTester, ThrowsExceptionOnErrorBind )  
{
  flags_.bindShouldError = true;
  ASSERT_THROW( createAndDeleteListener(), int );
}

TEST_F( SocketConnectionReceiverTester, DestructorClosesFD )  
{
  {
    createAndDeleteListener();
  }
  EXPECT_EQ( returnValues_.socket, inputValues_.close );
}

TEST_F( SocketConnectionReceiverTester, ListensToSocketFDItReceives )  
{
  createAndDeleteListener();
  EXPECT_EQ( returnValues_.socket, inputValues_.listen );
}

TEST_F( SocketConnectionReceiverTester, AcceptsConnectionsOnSocketFDItReceives )  
{
  SocketConnectionReceiver* receiver = createListener();
  receiver->nextConnection();

  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
  delete receiver;
}

TEST_F( SocketConnectionReceiverTester, PassesInCorrectSocketFDToAccept )  
{
  SocketConnectionReceiver* receiver = createListener();
  receiver->nextConnection();

  EXPECT_EQ( returnValues_.socket, inputValues_.accept );
  delete receiver;
}

TEST_F( SocketConnectionReceiverTester, ThrowsExceptionWhenAcceptFails )  
{
  SocketConnectionReceiver* receiver = createListener();
  flags_.acceptShouldError = true;

  ASSERT_THROW( receiver->nextConnection(), int );
  delete receiver;
}

TEST_F( SocketConnectionReceiverTester, NextConnectionReturnsCorrectFD )  
{
  SocketConnectionReceiver* receiver = createListener();
  int actual = receiver->nextConnection(); 

  ASSERT_EQ( returnValues_.accept, actual );
  delete receiver;
}
