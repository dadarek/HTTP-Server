#ifndef SOCKET_READER_H
#define SOCKET_READER_H

#include <string>

class SocketReader
{
  public:
    virtual ~SocketReader() { }

    virtual std::string readToEnd( int socketFD ) = 0;
};

#endif
