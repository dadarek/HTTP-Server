#include "MockFile.h"

MockFile::MockFile( MockFileInspector& inspector )
  : inspector_( inspector )
{ }

MockFile::~MockFile()
{ 
  inspector_.destroyed = true;
}

bool MockFile::isOpen()
{
  throw 0;
}

size_t MockFile::size()
{
  throw 0;
}

void MockFile::moveTo( size_t position )
{
  throw 0;
}

void MockFile::read( char* buffer, size_t size )
{
  throw 0;
}

void MockFile::close()
{
  inspector_.closed = true;
}

