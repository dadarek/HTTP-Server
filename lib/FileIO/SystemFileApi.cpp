#include "SystemFileApi.h"
#include "File.h"
#include "FileFactory.h"
#include "FileNotFoundException.h"

SystemFileApi::SystemFileApi( FileFactory& factory )
  : factory_( factory )
{ }

SystemFileApi::~SystemFileApi()
{ }

size_t SystemFileApi::readToEnd( const std::string path, char** whereToStore )
{
  File* file = open( path );
  size_t result = getContents( file, whereToStore );
  closeAndDelete( file );

  return result;
}

bool SystemFileApi::exists( const std::string path )
{
  File* file = factory_.open( path.c_str() );
  bool result = file->isOpen();
  delete file;
  return result;
}

size_t SystemFileApi::getContents( File* file, char** whereToStore )
{
  size_t fileSize = file->size();
  char* buffer = new char[ fileSize ];

  file->moveTo( 0 );
  file->read( buffer, fileSize );

  (*whereToStore) = buffer;
  return fileSize;
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
