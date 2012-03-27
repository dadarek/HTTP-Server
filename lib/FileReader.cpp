#include "FileReader.h"
#include "File.h"
#include "FileFactory.h"

FileReader::FileReader( FileFactory& factory )
  : factory_( factory )
{ }

FileReader::~FileReader()
{ }

std::string FileReader::readToEnd( const std::string path )
{
  File* file = open( path );
  std::string result = getContents( file );
  closeAndDelete( file );

  return result;
}

std::string FileReader::getContents( File* file )
{
  size_t fileSize = file->size();
  char* buffer = new char[ fileSize ];

  file->moveTo( 0 );
  file->read( buffer, fileSize );

  std::string contents( buffer );

  delete[] buffer;

  return contents;
}

void FileReader::closeAndDelete( File* file )
{
  file->close();
  delete file;
}

File* FileReader::open( const std::string path )
{
  File* file = factory_.open( path.c_str(), getOpenMode() );
  if( !file->isOpen() )
  {
    delete file;
    throw FILE_NOT_FOUND_EXCEPTION;
  }
  return file;
}

std::ios_base::openmode FileReader::getOpenMode()
{
  return std::ios::in | std::ios::ate | std::ios::binary;
}
