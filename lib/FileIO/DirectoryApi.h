#ifndef DIRECTORY_API_H
#define DIRECTORY_API_H

#include <dirent.h>

class DirectoryApi
{
  public:
    virtual ~DirectoryApi() { }

    virtual DIR* opendir( const char* path ) = 0;
    virtual struct dirent* readdir( DIR* directory ) = 0;
    virtual void closedir( DIR* directory ) = 0;
};

#endif
