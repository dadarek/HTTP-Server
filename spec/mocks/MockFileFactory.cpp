#include "MockFileFactory.h"
#include "MockFile.h"

MockFileFactory::MockFileFactory()
{ }

MockFileFactory::~MockFileFactory()
{ }

File* MockFileFactory::open( const char*, std::ios_base::openmode )
{
  return new MockFile();
}

