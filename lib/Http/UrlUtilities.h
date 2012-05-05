#ifndef URL_UTILITIES_H
#define URL_UTILITIES_H

#include <string>

class UrlUtilities
{
  private:
    static const char* OPEN_BRACE;
    static const char* CLOSE_BRACE;
    static const char* QUOTE;

    UrlUtilities();
    virtual ~UrlUtilities();

  public:
    static std::string encode( const char* );
    static std::string decode( const char* );

  private:
    static bool isEncoded( char );
    static char translate( const char* );
};

#endif
