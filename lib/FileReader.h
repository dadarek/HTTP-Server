#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileApi;

class FileReader
{
  public:
    static const int FILE_NOT_FOUND_EXCEPTION = 1;

  private:
    FileApi& fileApi_;

  public:
    FileReader( FileApi& fileApi );
    virtual ~FileReader();

    std::string readToEnd( std::string path );
};

#endif
