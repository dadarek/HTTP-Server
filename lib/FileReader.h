#ifndef FILE_READER_H
#define FILE_READER_H

#include "FileFactory.h"
#include <string>

class FileApi;

class FileReader
{
  public:
    static const int FILE_NOT_FOUND_EXCEPTION = 1;

  private:
    FileApi& fileApi_;
    FileFactory& factory_;

  public:
    FileReader( FileApi& fileApi, FileFactory& factory );
    virtual ~FileReader();

    std::string readToEnd( std::string path );
};

#endif
