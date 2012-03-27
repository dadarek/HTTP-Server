#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <iostream>

class FileFactory;
class File;

class FileReader
{
  private:
    FileFactory& factory_;

  public:
    FileReader( FileFactory& factory );
    virtual ~FileReader();

    std::string readToEnd( std::string path );

  private:
    std::ios_base::openmode getOpenMode();
    File* open( const std::string path );
    std::string getContents( File* file );
    void closeAndDelete( File* file );
};

#endif
