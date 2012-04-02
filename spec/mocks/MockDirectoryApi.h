#ifndef MOCK_DIRECTORY_API_H
#define MOCK_DIRECTORY_API_H

#include "DirectoryApi.h"
#include <string>

class MockDirectoryApi
  : public DirectoryApi
{
  public:
    std::string directoryOpened_;

    MockDirectoryApi();
    virtual ~MockDirectoryApi();

    DIR* opendir( const char* path );
    struct dirent* readdir( DIR* directory );
};
#endif
