#ifndef SYSTEM_FILE_API_H
#define SYSTEM_FILE_API_H

#include "FileApi.h"

#include <string>
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

    std::string readToEnd( std::string path );
    bool exists( std::string path );

  private:
    std::ios_base::openmode getOpenMode();
    File* open( const std::string path );
    std::string getContents( File* file );
    void closeAndDelete( File* file );
};

#endif
