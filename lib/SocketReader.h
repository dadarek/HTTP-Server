#ifndef SOCKET_READER_H
#define SOCKET_READER_H

#include <string>

class SocketApi;

class SocketReader
{
  public:
    virtual ~SocketReader() { }

    virtual std::string readToEnd( int socketFD, const char* terminator ) = 0;
};

#endif
