#include "UrlUtilities.h"

const char* UrlUtilities::OPEN_BRACE = "%7B";
const char* UrlUtilities::CLOSE_BRACE = "%7D";
const char* UrlUtilities::QUOTE = "%22";

std::string UrlUtilities::encode( const char* value )
{
  std::string result;
  for( size_t i = 0; i < strlen(value); i++ )
  {
    switch( value[i] )
    {
      case '{':
        result += OPEN_BRACE;
        break;
      case '}':
        result += CLOSE_BRACE;
        break;
      case '"':
        result += QUOTE;
        break;
      default:
        result += value[i];
        break;
    }
  }

  return result;
}

std::string UrlUtilities::decode( const char* value )
{
  std::string result;

  for(size_t i = 0; i < strlen(value); )
  {
    if( isEncoded( value[i] ) )
    {
      result += translate(value + i);
      i += 3;
    }
    else
    {
      result += value[i];
      i++;
    }
  }
  return result;
}

bool UrlUtilities::isEncoded( char c )
{
  return c == '%';
}

char UrlUtilities::translate( const char* encoded )
{
  std::string nextChar(encoded, 3);
  if(nextChar == OPEN_BRACE) return '{';
  if(nextChar == CLOSE_BRACE) return '}';
  if(nextChar == QUOTE) return '"';
  throw 0;
}
