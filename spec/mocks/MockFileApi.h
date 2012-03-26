#ifndef MOCK_FILE_API_H
#define MOCK_FILE_API_H

#include "FileApi.h"

class MockFileApi
  : public FileApi
{
  public:
    MockFileApi();
    ~MockFileApi();

    void open( const char* path );
    bool is_open();
    bool good();
    void close();
};

#endif
