#ifndef MOCK_FILE_H
#define MOCK_FILE_H

#include "File.h"

class MockFile
  : public File
{
  public:
    MockFile();
    virtual ~MockFile();

    bool isOpen();
    size_t size();
    void moveTo( size_t position );
    void read( char* buffer, size_t size );
    void close();
};

#endif
