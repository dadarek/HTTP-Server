#include "gtest/gtest.h"
#include "InvalidHttpRequestHeadersException.h"

TEST( InvalidHttpRequestHeadersExceptionTests, HasCorrectErrorMessage )
{
  InvalidHttpRequestHeadersException exception;
  const char* expected = "Invalid HTTP Request headers.";
  ASSERT_STREQ( expected, exception.what() );
}

