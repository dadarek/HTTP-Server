#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileReader
{
  public:
    virtual ~FileReader() { }

    virtual std::string readToEnd( std::string path ) = 0;
    virtual bool exists( std::string path ) = 0;
};

#endif
