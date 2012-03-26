#include "SystemFileFactory.h"
#include "SystemFile.h"

SystemFileFactory::SystemFileFactory()
{ }

SystemFileFactory::~SystemFileFactory()
{ }

File* SystemFileFactory::open( const char* path, std::ios_base::openmode fileMode )
{ 
  return new SystemFile( path, fileMode );
}
