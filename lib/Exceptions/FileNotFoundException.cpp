#include "FileNotFoundException.h"

FileNotFoundException::FileNotFoundException()
  : std::runtime_error( "File not found." )
{ }

FileNotFoundException::~FileNotFoundException() throw()
{ }
