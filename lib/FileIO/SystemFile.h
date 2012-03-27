#ifndef SYSTEM_FILE_H
#define SYSTEM_FILE_H

#include "File.h"
#include <iostream>
#include <fstream>

class SystemFile
  : public File
{
  private:
    std::ifstream file_;

  public:
    SystemFile( const char* path, std::ios_base::openmode fileMode );
    virtual ~SystemFile();

    bool isOpen();
    size_t size();
    void moveTo( size_t position );
    void read( char* buffer, size_t size );
    void close();
};

#endif
