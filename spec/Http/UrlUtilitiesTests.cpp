#include "gtest/gtest.h"
#include "UrlUtilities.h"

class UrlUtilitiesTests
  : public ::testing::Test
{
  public:
    const char* const OPEN_BRACE;
    const char* const CLOSE_BRACE;
    const char* const QUOTE;

    UrlUtilitiesTests() 
      : OPEN_BRACE( "%7B" )
      , CLOSE_BRACE( "%7D" )
      , QUOTE( "%22" )
  {}
};

TEST_F( UrlUtilitiesTests, DecodesSingleCharacters )
{
  ASSERT_STREQ("{", UrlUtilities::decode(OPEN_BRACE).c_str());
  ASSERT_STREQ("}", UrlUtilities::decode(CLOSE_BRACE).c_str());
  ASSERT_STREQ("\"", UrlUtilities::decode(QUOTE).c_str());
}

TEST_F( UrlUtilitiesTests, DecodesMultipleCharacters )
{
  char code[100];
  sprintf( code, "%s%s%s%s", OPEN_BRACE, CLOSE_BRACE, OPEN_BRACE, QUOTE );
  ASSERT_STREQ("{}{\"", UrlUtilities::decode(code).c_str());
}

TEST_F( UrlUtilitiesTests, DecodesMixedCodes )
{
  char code[100];
  sprintf( code, "%s8%st%shlight%s%s", OPEN_BRACE, CLOSE_BRACE, OPEN_BRACE, OPEN_BRACE, QUOTE );
  ASSERT_STREQ("{8}t{hlight{\"", UrlUtilities::decode(code).c_str());
}

TEST_F( UrlUtilitiesTests, EncodesSingleCharacters )
{
  ASSERT_STREQ( OPEN_BRACE, UrlUtilities::encode("{").c_str() );
  ASSERT_STREQ( CLOSE_BRACE, UrlUtilities::encode("}").c_str() );
  ASSERT_STREQ( QUOTE, UrlUtilities::encode("\"").c_str() );
}

TEST_F( UrlUtilitiesTests, EncodesMultipleCharacters )
{
  char expected[100];
  sprintf(expected, "%s%s%s%s", OPEN_BRACE, CLOSE_BRACE, OPEN_BRACE, QUOTE);
  ASSERT_STREQ( expected, UrlUtilities::encode("{}{\"").c_str() );
}

TEST_F( UrlUtilitiesTests, EncodesMixedCharacters )
{
  char expected[100];
  sprintf(expected, "He%sl%slo W%s%s", OPEN_BRACE, CLOSE_BRACE, OPEN_BRACE, QUOTE);
  ASSERT_STREQ( expected, UrlUtilities::encode("He{l}lo W{\"").c_str() );
}
