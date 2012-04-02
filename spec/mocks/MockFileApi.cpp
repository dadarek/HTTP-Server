#include "MockFileApi.h"

MockFileApi::MockFileApi()
  : fileContents_( 0 )
  , fileSize_( (size_t) 0 )
  , existsReturnValue_( false )
{ }

MockFileApi::~MockFileApi()
{ }

size_t MockFileApi::readToEnd( std::string path, char** whereToStore )
{
  readToEndInput_ = path;
  (*whereToStore) = new char[fileSize_];
  memcpy( (*whereToStore), fileContents_, fileSize_ );
  return fileSize_;
}

bool MockFileApi::exists( std::string path )
{
  existsInput_ = path;
  return existsReturnValue_;
}
