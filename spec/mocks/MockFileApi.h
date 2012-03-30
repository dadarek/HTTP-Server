#ifndef MOCK_FILE_API_H
#define MOCK_FILE_API_H

#include "FileApi.h"

class MockFileApi
  : public FileApi
{
  public:
    std::string readToEndInput_;
    std::string readToEndReturnValue_;

    std::string existsInput_;
    bool existsReturnValue_;

    MockFileApi();
    virtual ~MockFileApi();

    std::string readToEnd( std::string path );
    bool exists( std::string path );
};

#endif
