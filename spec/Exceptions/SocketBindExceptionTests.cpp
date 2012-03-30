#include "gtest/gtest.h"
#include "SocketBindException.h"

TEST( SocketBindException, HasCorrectErrorMessage )
{
  SocketBindException exception;
  const char* expected = "Error binding to socket.";
  ASSERT_STREQ( expected, exception.what() );
}

