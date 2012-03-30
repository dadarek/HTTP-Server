#include "MockFileReader.h"

MockFileReader::MockFileReader()
  : existsReturnValue_( false )
{ }

MockFileReader::~MockFileReader()
{ }

std::string MockFileReader::readToEnd( std::string path )
{
  readToEndInput_ = path;
  return readToEndReturnValue_;
}

bool MockFileReader::exists( std::string path )
{
  existsInput_ = path;
  return existsReturnValue_;
}
