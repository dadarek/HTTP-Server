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
  file->read( 0, fileSize );

  delete file;

  return "";
}

