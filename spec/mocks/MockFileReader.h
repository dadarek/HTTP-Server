#ifndef MOCK_FILE_READER_H
#define MOCK_FILE_READER_H

#include "FileReader.h"

class MockFileReader
  : public FileReader
{
  public:
    std::string fileRead_;
    std::string returnValue_;

    std::string existsInput_;
    bool existsReturnValue_;

    MockFileReader();
    virtual ~MockFileReader();

    std::string readToEnd( std::string path );
    bool exists( std::string path );
};

#endif
