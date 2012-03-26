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
  File* file = factory_.open( path.c_str(), (std::ios_base::openmode) 0 );
  file->close();
  
  if( !file->isOpen() )
    throw FILE_NOT_FOUND_EXCEPTION;

  size_t fileSize = file->size();
  char* buffer = new char[ fileSize ];
  file->read( buffer, fileSize );

  std::string result( buffer );
  delete[] buffer;

  delete file;

  return result;
}

