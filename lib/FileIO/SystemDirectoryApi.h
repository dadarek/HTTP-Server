#ifndef SYSTEM_DIRECTORY_API_H
#define SYSTEM_DIRECTORY_API_H

#include "DirectoryApi.h"

class SystemDirectoryApi
  : public DirectoryApi
{
  public:
    SystemDirectoryApi();
    virtual ~SystemDirectoryApi();

    DIR* opendir( const char* path ) = 0;
    struct dirent* readdir( DIR* directory );

};
#endif
