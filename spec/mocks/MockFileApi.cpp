#include "MockFileApi.h"

MockFileApi::MockFileApi()
  : existsReturnValue_( false )
{ }

MockFileApi::~MockFileApi()
{ }

std::string MockFileApi::readToEnd( std::string path )
{
  readToEndInput_ = path;
  return readToEndReturnValue_;
}

bool MockFileApi::exists( std::string path )
{
  existsInput_ = path;
  return existsReturnValue_;
}
