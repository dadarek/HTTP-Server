#include "gtest/gtest.h"
#include "ThreadStartException.h"

TEST( ThreadStartException, HasCorrectErrorMessage )
{
  ThreadStartException exception;
  const char* expected = "Failed to start thread.";
  ASSERT_STREQ( expected, exception.what() );
}

