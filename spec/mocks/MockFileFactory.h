#ifndef MOCK_FILE_FACTORY_H
#define MOCK_FILE_FACTORY_H

#include "FileFactory.h"
#include "MockFile.h"

class File;

class MockFileFactory
  : public FileFactory
{
  public:
    bool openCalled_;
    std::string path_;

    MockFileInspector inspector_;

    MockFileFactory();
    virtual ~MockFileFactory();

    File* open( const char* path, std::ios_base::openmode mode ); 
};

#endif
