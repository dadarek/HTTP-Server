#include "SystemDirectoryApi.h"

SystemDirectoryApi::SystemDirectoryApi()
{ }

SystemDirectoryApi::~SystemDirectoryApi()
{ }

DIR* SystemDirectoryApi::opendir( const char* path )
{
  return ::opendir( path );
}

struct dirent* SystemDirectoryApi::readdir( DIR* directory )
{
  return ::readdir( directory );
}
