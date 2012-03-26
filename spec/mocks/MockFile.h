#ifndef MOCK_FILE_H
#define MOCK_FILE_H

#include "File.h"

struct MockFileInspector
{
  bool closed;
  bool destroyed;
  bool checkedIfOpen;
  bool openReturnValue;

  MockFileInspector()
    : closed( false )
    , destroyed ( false )
    , checkedIfOpen( false )
    , openReturnValue( true )
  { }
};

class MockFile
  : public File
{
  public:
    MockFileInspector& inspector_;

    MockFile( MockFileInspector& inspector );
    virtual ~MockFile();

    bool isOpen();
    size_t size();
    void moveTo( size_t position );
    void read( char* buffer, size_t size );
    void close();
};

#endif