#include "MockFile.h"

MockFile::MockFile()
{ }

MockFile::~MockFile()
{ }

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
  throw 0;
}

