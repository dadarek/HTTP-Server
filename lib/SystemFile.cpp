#include "SystemFile.h"

SystemFile::SystemFile( const char* path, std::ios_base::openmode fileMode )
  : file_( path, fileMode )
{ }

SystemFile::~SystemFile()
{ }

bool SystemFile::isOpen()
{
  return file_.is_open();
}

size_t SystemFile::size()
{
  return file_.tellg();
}

void SystemFile::moveTo( size_t position )
{
  file_.seekg( position );
}

void SystemFile::read( char* buffer, size_t size )
{
  file_.read( buffer, size );
}

void SystemFile::close()
{
  file_.close();
}

