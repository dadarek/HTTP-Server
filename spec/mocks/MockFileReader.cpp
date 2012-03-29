#include "MockFileReader.h"

MockFileReader::MockFileReader()
{ }

MockFileReader::~MockFileReader()
{ }

std::string MockFileReader::readToEnd( std::string path )
{
  fileRead_ = path;
  return returnValue_;
}

