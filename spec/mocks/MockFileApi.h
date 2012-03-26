#ifndef MOCK_FILE_API_H
#define MOCK_FILE_API_H

#include <string>
#include "FileApi.h"

class MockFileApi
  : public FileApi
{
  public:
    bool openCalled_;
    bool closeCalled_;
    bool isOpenCalled_;
    bool isGoodCalled_;

    std::string path_;

    MockFileApi();
    ~MockFileApi();

    void open( const char* path );
    bool is_open();
    bool good();
    void close();
};

#endif
