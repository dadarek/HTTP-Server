#include "MockDirectoryApi.h"
#include <stdexcept>

MockDirectoryApi::MockDirectoryApi()
  : opendir_returnValue_( 0 )
  , readdir_input_( 0 )
  , closedir_input_( 0 )
  , closeDirCalled_( false )
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
  if( closeDirCalled_ )
    throw std::runtime_error( "Can't read a closed directory." );

  readdir_input_ = directory;
  timesReaddirCalled_++;
  if( 0 != readdir_returnValues_ )
    return *(readdir_returnValues_++);
  return 0;
}

void MockDirectoryApi::closedir( DIR* directory )
{
  closeDirCalled_ = true;
  closedir_input_ = directory;
}
