#include "MockFile.h"

#include <iostream>

MockFile::MockFile( MockFileInspector& inspector )
  : inspector_( inspector )
{ }

MockFile::~MockFile()
{ 
  throwIfDestroyed("Can't twice destroy a destroyed file.");
  inspector_.destroyed = true;
}

bool MockFile::isOpen()
{
  throwIfDestroyed("Can't open a destroyed file.");

  inspector_.checkedIfOpen = true;
  return inspector_.openReturnValue;
}

size_t MockFile::size()
{
  throwIfDestroyed("Can't size a destroyed file.");
  throwIfClosed("Can't size a closed file.");

  inspector_.sizeChecked = true;
  return inspector_.sizeReturnValue;
}

void MockFile::moveTo( size_t )
{
  throwIfDestroyed("Can't move a destroyed file.");
  throwIfClosed("Can't move a closed file.");

  throw 0;
}
void MockFile::read( char* buffer, size_t size )
{
  throwIfDestroyed("Can't read a destroyed file.");
  throwIfClosed("Can't read a closed file.");

  inspector_.inputValueForRead = size;
  strcpy( buffer, inspector_.buffer );
}

void MockFile::close()
{
  throwIfDestroyed("Can't destroy a destroyed file.");

  inspector_.closed = true;
}

void MockFile::throwIfClosed( const char* message )
{
  if( inspector_.closed )
    throw MockFileException( message );
}
void MockFile::throwIfDestroyed( const char* message )
{
  if( inspector_.destroyed )
    throw MockFileException( message );
}
