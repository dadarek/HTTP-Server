#include "gtest/gtest.h"
#include "FileNotFoundException.h"

TEST( FileNotFoundException, HasCorrectErrorMessage )
{
  FileNotFoundException exception;
  const char* expected = "File not found.";
  ASSERT_STREQ( expected, exception.what() );
}

