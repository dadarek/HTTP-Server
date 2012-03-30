#ifndef SYSTEM_FILE_READER_H
#define SYSTEM_FILE_READER_H

#include "FileReader.h"

#include <string>
#include <iostream>

class FileFactory;
class File;

class SystemFileReader
  : public FileReader
{
  private:
    FileFactory& factory_;

  public:
    SystemFileReader( FileFactory& factory );
    virtual ~SystemFileReader();

    std::string readToEnd( std::string path );
    bool exists( std::string path );

  private:
    std::ios_base::openmode getOpenMode();
    File* open( const std::string path );
    std::string getContents( File* file );
    void closeAndDelete( File* file );
};

#endif
