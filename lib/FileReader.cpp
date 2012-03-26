#include "FileReader.h"

FileReader::FileReader( FileApi& fileApi )
  : fileApi_( fileApi )
{ }

FileReader::~FileReader()
{ }

std::string readToEnd( const std::string location )
{ throw 0; }
