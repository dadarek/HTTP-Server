#include "MockFileFactory.h"
#include "MockFile.h"

MockFileFactory::MockFileFactory()
{ }

MockFileFactory::~MockFileFactory()
{ }

File* MockFileFactory::open( const char* path, std::ios_base::openmode )
{
  openCalled_ = true;
  path_ = std::string( path );
  return new MockFile( inspector_ );
}

