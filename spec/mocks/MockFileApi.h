#ifndef MOCK_FILE_API_H
#define MOCK_FILE_API_H

#include "FileApi.h"

class MockFileApi
  : public FileApi
{
  public:
    std::string readToEndInput_;
    const char* fileContents_;
    size_t fileSize_;

    std::string existsInput_;
    bool existsReturnValue_;

    MockFileApi();
    virtual ~MockFileApi();

    size_t readToEnd( std::string path, char** whereToStore );
    bool exists( std::string path );
};

#endif
