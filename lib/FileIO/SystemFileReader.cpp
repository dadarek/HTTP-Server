#include "SystemFileReader.h"
#include "File.h"
#include "FileFactory.h"
#include "FileNotFoundException.h"

SystemFileReader::SystemFileReader( FileFactory& factory )
  : factory_( factory )
{ }

SystemFileReader::~SystemFileReader()
{ }

std::string SystemFileReader::readToEnd( const std::string path )
{
  File* file = open( path );
  std::string result = getContents( file );
  closeAndDelete( file );

  return result;
}

bool SystemFileReader::exists( const std::string path )
{
  throw 1;
}

std::string SystemFileReader::getContents( File* file )
{
  size_t fileSize = file->size();
  char* buffer = new char[ fileSize ];

  file->moveTo( 0 );
  file->read( buffer, fileSize );

  std::string contents( buffer );

  delete[] buffer;

  return contents;
}

void SystemFileReader::closeAndDelete( File* file )
{
  file->close();
  delete file;
}

File* SystemFileReader::open( const std::string path )
{
  File* file = factory_.open( path.c_str(), getOpenMode() );
  if( !file->isOpen() )
  {
    delete file;
    throw FileNotFoundException();
  }
  return file;
}

std::ios_base::openmode SystemFileReader::getOpenMode()
{
  return std::ios::in | std::ios::ate | std::ios::binary;
}
