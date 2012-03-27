#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileFactory;
class File;

class FileReader
{
  public:
    static const int FILE_NOT_FOUND_EXCEPTION = 1;

  private:
    FileFactory& factory_;

  public:
    FileReader( FileFactory& factory );
    virtual ~FileReader();

    std::string readToEnd( std::string path );

  private:
    File* open( const std::string path );
};

#endif
