#ifndef SYSTEM_FILE_FACTORY_H
#define SYSTEM_FILE_FACTORY_H

#include "FileFactory.h"

class SystemFileFactory
  : public FileFactory
{
  public:
    SystemFileFactory();
    virtual ~SystemFileFactory();

    File* open( const char* path );
    File* open( const char* path, std::ios_base::openmode fileMode );
};


#endif
