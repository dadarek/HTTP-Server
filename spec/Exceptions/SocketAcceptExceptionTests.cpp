#include "gtest/gtest.h"
#include "SocketAcceptException.h"

TEST( SocketAcceptException, HasCorrectErrorMessage )
{
  SocketAcceptException exception;
  const char* expected = "Error accepting next incoming connection on socket.";
  ASSERT_STREQ( expected, exception.what() );
}

