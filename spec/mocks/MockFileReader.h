#ifndef MOCK_FILE_READER_H
#define MOCK_FILE_READER_H

#include "FileReader.h"

class MockFileReader
  : public FileReader
{
  public:
    MockFileReader();
    virtual ~MockFileReader();

    std::string readToEnd( std::string path );
};

#endif
