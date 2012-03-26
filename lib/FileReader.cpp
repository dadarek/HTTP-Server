#include "FileReader.h"
#include "FileApi.h"
#include "File.h"
#include "FileFactory.h"

FileReader::FileReader( FileApi& fileApi, FileFactory& factory )
  : fileApi_( fileApi )
  , factory_( factory )
{ }

FileReader::~FileReader()
{ }

std::string FileReader::readToEnd( const std::string path )
{
  File* file = factory_.open( path.c_str(), (std::ios_base::openmode) 0 );
  file->close();

  fileApi_.open( path.c_str() );
  fileApi_.close();
  
  if( ! fileApi_.is_open() )
    throw FILE_NOT_FOUND_EXCEPTION;

  while( fileApi_.good() ) { }

  return "";
}

