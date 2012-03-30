#ifndef FILE_API_H
#define FILE_API_H

#include <string>

class FileApi
{
  public:
    virtual ~FileApi() { }

    virtual std::string readToEnd( std::string path ) = 0;
    virtual bool exists( std::string path ) = 0;
};

#endif
