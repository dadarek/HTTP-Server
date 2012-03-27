#include "MockSocketReader.h"

MockSocketReader::MockSocketReader()
{ }

MockSocketReader::~MockSocketReader()
{ }

std::string MockSocketReader::readToEnd( int )
{
  throw 0;
}
