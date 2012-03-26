#include "MockFile.h"

#include <iostream>

MockFile::MockFile( MockFileInspector& inspector )
  : inspector_( inspector )
{ }

MockFile::~MockFile()
{ 
  inspector_.destroyed = true;
}

bool MockFile::isOpen()
{
  inspector_.checkedIfOpen = true;
  return inspector_.openReturnValue;
}

size_t MockFile::size()
{
  inspector_.sizeChecked = true;
  return inspector_.sizeReturnValue;
}

void MockFile::moveTo( size_t position )
{
  throw 0;
}
void MockFile::read( char* buffer, size_t size )
{
  inspector_.inputValueForRead = size;
  strcpy( buffer, inspector_.buffer );
}

void MockFile::close()
{
  inspector_.closed = true;
}

