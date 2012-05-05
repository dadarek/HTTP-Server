#include "UrlUtilities.h"

std::string UrlUtilities::encode( const char* value )
{
  std::string result;

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
  if(nextChar == "%7B") return '{';
  if(nextChar == "%7D") return '}';
  if(nextChar == "%22") return '"';
  throw 0;
}
