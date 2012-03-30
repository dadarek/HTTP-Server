#include "MockFileFactory.h"
#include "MockFile.h"

MockFileFactory::MockFileFactory( MockFileInspector& inspector )
  : inspector_( inspector )
  , openmode_( std::ios::in ^ std::ios::in )
{ }

MockFileFactory::~MockFileFactory()
{ }

File* MockFileFactory::open( const char* path )
{
  openCalled_ = true;
  path_ = std::string( path );
  return new MockFile( inspector_ );
}

File* MockFileFactory::open( const char* path, std::ios_base::openmode openmode )
{
  openmode_ = openmode;
  openCalled_ = true;
  path_ = std::string( path );
  return new MockFile( inspector_ );
}

