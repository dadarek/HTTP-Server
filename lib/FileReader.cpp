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
  std::ios_base::openmode openMode =
     std::ios::in | std::ios::ate | std::ios::binary;

  File* file = factory_.open( path.c_str(), openMode );
  
  if( !file->isOpen() )
    throw FILE_NOT_FOUND_EXCEPTION;

  size_t fileSize = file->size();
  char* buffer = new char[ fileSize ];
  file->read( buffer, fileSize );

  std::string result( buffer );
  delete[] buffer;

  file->close();
  delete file;

  return result;
}

