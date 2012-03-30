#include "MockFileReader.h"

MockFileReader::MockFileReader()
  : existsReturnValue_( false )
{ }

MockFileReader::~MockFileReader()
{ }

std::string MockFileReader::readToEnd( std::string path )
{
  fileRead_ = path;
  return returnValue_;
}

bool MockFileReader::exists( std::string path )
{
  existsInput_ = path;
  return existsReturnValue_;
}
