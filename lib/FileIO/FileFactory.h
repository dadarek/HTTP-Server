#ifndef FILE_FACTORY_H
#define FILE_FACTORY_H

#include <iostream>

class File;

class FileFactory
{
  public:
    virtual ~FileFactory() { }

    virtual File* open( const char* path, std::ios_base::openmode mode ) = 0;
};

#endif
