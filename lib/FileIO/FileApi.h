#ifndef FILE_API_H
#define FILE_API_H

#include <string>

class FileApi
{
  public:
    virtual ~FileApi() { }

    virtual size_t readToEnd( std::string path, char** whereToStore ) = 0;
    virtual bool exists( std::string path ) = 0;
};

#endif
