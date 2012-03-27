#ifndef MOCK_FILE_H
#define MOCK_FILE_H

#include "File.h"
#include <stdexcept>

class MockFileException
  : public std::runtime_error
{
  public:
    MockFileException( const char* message )
      : std::runtime_error( message )
    { }
};

struct MockFileInspector
{
  bool closed;
  bool destroyed;
  bool checkedIfOpen;
  bool openReturnValue;
  bool sizeChecked;
  size_t sizeReturnValue;
  size_t inputValueForRead;
  char buffer[100];

  MockFileInspector()
    : closed( false )
    , destroyed ( false )
    , checkedIfOpen( false )
    , openReturnValue( true )
    , sizeChecked( false )
    , sizeReturnValue( 0 )
    , inputValueForRead( 0 )
  { 
    buffer[0] = '\0';
  }
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

  private:
    void throwIfDestroyed( const char* message );
    void throwIfClosed( const char* message );
    void throwIfDidNotCheckOpen( const char* message );
};

#endif
