#include "MockDirectoryApi.h"

MockDirectoryApi::MockDirectoryApi()
  : opendir_returnValue_( 0 )
  , readdir_input_( 0 )
{ }

MockDirectoryApi::~MockDirectoryApi()
{ }

DIR* MockDirectoryApi::opendir( const char* path )
{
  directoryOpened_ = path;
  return opendir_returnValue_;
}

struct dirent* MockDirectoryApi::readdir( DIR* directory )
{
  readdir_input_ = directory;
  return 0;
}

