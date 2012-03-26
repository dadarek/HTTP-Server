#ifndef FILE_H
#define FILE_H

#include "stddef.h"

class File
{
  public:
    virtual ~File() { }

    virtual bool isOpen() = 0;
    virtual size_t size() = 0;
    virtual void moveTo( size_t position ) = 0;
    virtual void read( char* buffer, size_t size ) = 0;
    virtual void close() = 0;
};

#endif
