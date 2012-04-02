#include "MockDirectoryApi.h"

MockDirectoryApi::MockDirectoryApi()
{ }

MockDirectoryApi::~MockDirectoryApi()
{ }

DIR* MockDirectoryApi::opendir( const char* path )
{
  directoryOpened_ = path;
  return 0;
}

struct dirent* MockDirectoryApi::readdir( DIR* directory )
{
  throw 0;
}

