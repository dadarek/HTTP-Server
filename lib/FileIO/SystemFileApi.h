#ifndef SYSTEM_FILE_API_H
#define SYSTEM_FILE_API_H

#include "FileApi.h"

#include <iostream>

class FileFactory;
class File;

class SystemFileApi
  : public FileApi
{
  private:
    FileFactory& factory_;

  public:
    SystemFileApi( FileFactory& factory );
    virtual ~SystemFileApi();

    size_t readToEnd( std::string path, char** whereToStore );
    bool exists( std::string path );

  private:
    std::ios_base::openmode getOpenMode();
    File* open( const std::string path );
    size_t getContents( File* file, char** whereToStore );
    void closeAndDelete( File* file );
};

#endif
