#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileApi;

class FileReader
{
  private:
    FileApi& fileApi_;

  public:
    FileReader( FileApi& fileApi );
    virtual ~FileReader();

    std::string readToEnd( std::string path );
};

#endif
