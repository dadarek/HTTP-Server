#include "gtest/gtest.h"
#include "SocketCreateException.h"

TEST( SocketCreateException, HasCorrectErrorMessage )
{
  SocketCreateException exception;
  const char* expected = "Error creating socket.";
  ASSERT_STREQ( expected, exception.what() );
}

