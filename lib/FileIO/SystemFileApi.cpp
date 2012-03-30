#include "SystemFileApi.h"
#include "File.h"
#include "FileFactory.h"
#include "FileNotFoundException.h"

SystemFileApi::SystemFileApi( FileFactory& factory )
  : factory_( factory )
{ }

SystemFileApi::~SystemFileApi()
{ }

std::string SystemFileApi::readToEnd( const std::string path )
{
  File* file = open( path );
  std::string result = getContents( file );
  closeAndDelete( file );

  return result;
}

bool SystemFileApi::exists( const std::string path )
{
  File* file = factory_.open( path.c_str(), (std::ios_base::openmode) -1 );
}

std::string SystemFileApi::getContents( File* file )
{
  size_t fileSize = file->size();
  char* buffer = new char[ fileSize ];

  file->moveTo( 0 );
  file->read( buffer, fileSize );

  std::string contents( buffer );

  delete[] buffer;

  return contents;
}

void SystemFileApi::closeAndDelete( File* file )
{
  file->close();
  delete file;
}

File* SystemFileApi::open( const std::string path )
{
  File* file = factory_.open( path.c_str(), getOpenMode() );
  if( !file->isOpen() )
  {
    delete file;
    throw FileNotFoundException();
  }
  return file;
}

std::ios_base::openmode SystemFileApi::getOpenMode()
{
  return std::ios::in | std::ios::ate | std::ios::binary;
}
