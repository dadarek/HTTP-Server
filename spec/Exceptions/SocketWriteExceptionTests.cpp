#include "gtest/gtest.h"
#include "SocketWriteException.h"

TEST( SocketWriteException, HasCorrectErrorMessage )
{
  SocketWriteException exception;
  const char* expected = "Error writing to socket.";
  ASSERT_STREQ( expected, exception.what() );
}

