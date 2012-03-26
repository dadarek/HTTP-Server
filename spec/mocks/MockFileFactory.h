#ifndef MOCK_FILE_FACTORY_H
#define MOCK_FILE_FACTORY_H

#include "FileFactory.h"

class File;

class MockFileFactory
  : FileFactory
{
  public:
    MockFileFactory();
    virtual ~MockFileFactory();

    File* open( const char* path, std::ios_base::openmode mode ); 
};

#endif
