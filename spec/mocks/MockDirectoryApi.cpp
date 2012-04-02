#include "MockDirectoryApi.h"

MockDirectoryApi::MockDirectoryApi()
  : opendir_returnValue_( 0 )
  , readdir_input_( 0 )
  , readdir_returnValues_( 0 )
  , timesReaddirCalled_( 0 )
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
  printf("here\n");
  timesReaddirCalled_++;
  if( 0 != readdir_returnValues_ )
    return *(readdir_returnValues_++);
  return 0;
}

