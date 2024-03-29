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
  throwIfDidNotCheckOpen("Can't size if you didn't check open.");

  inspector_.sizeChecked = true;
  return inspector_.sizeReturnValue;
}

void MockFile::moveTo( size_t position )
{
  throwIfDestroyed("Can't move a destroyed file.");
  throwIfClosed("Can't move a closed file.");
  throwIfDidNotCheckOpen("Can't move if you didn't check open.");

  inspector_.movedToBeginning = position == (size_t) 0;

}
void MockFile::read( char* buffer, size_t size )
{
  throwIfDestroyed("Can't read a destroyed file.");
  throwIfClosed("Can't read a closed file.");
  throwIfDidNotCheckOpen("Can't read if you didn't check open.");
  throwIfDidNotCheckSize("Can't read if you didn't check size.");
  throwIfDidNotMoveToBeginning("Can't read if you don't move to beginning.");

  inspector_.inputValueForRead = size;
  memcpy( buffer, inspector_.buffer, inspector_.sizeReturnValue );
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

void MockFile::throwIfDidNotCheckOpen( const char* message )
{
  if( !inspector_.checkedIfOpen )
    throw MockFileException( message );
}

void MockFile::throwIfDidNotCheckSize( const char* message )
{
  if( !inspector_.sizeChecked )
    throw MockFileException( message );
}

void MockFile::throwIfDidNotMoveToBeginning( const char* message )
{
  if( !inspector_.movedToBeginning )
    throw MockFileException( message );
}
