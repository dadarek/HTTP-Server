#include "gtest/gtest.h"
#include "SocketReadException.h"

TEST( SocketReadException, HasCorrectErrorMessage )
{
  SocketReadException exception;
  const char* expected = "Error reading socket.";
  ASSERT_STREQ( expected, exception.what() );
}

