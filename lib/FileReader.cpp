#include "FileReader.h"
#include "FileApi.h"

FileReader::FileReader( FileApi& fileApi )
  : fileApi_( fileApi )
{ }

FileReader::~FileReader()
{ }

std::string FileReader::readToEnd( const std::string path )
{
  fileApi_.open( path.c_str() );
  fileApi_.close();
  
  if( ! fileApi_.is_open() )
    throw FILE_NOT_FOUND_EXCEPTION;

  while( fileApi_.good() ) { }

  return "";
}

