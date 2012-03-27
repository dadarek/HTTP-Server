#ifndef MOCK_SOCKET_READER_H
#define MOCK_SOCKET_READER_H

#include "SocketReader.h"

class MockSocketReader
  : public SocketReader
{
  public:
    bool readToEnd_;
    int socketFDRead_;
    std::string readToEndReturnValue_;

    MockSocketReader();
    virtual ~MockSocketReader();

    std::string readToEnd( int socketFD );

};
#endif
