#ifndef SOCKET_READER_H
#define SOCKET_READER_H

#include <iostream>

class SocketApi;

class SocketReader
{
  public:
    static const int READ_EXCEPTION = 1;

  private:
    SocketApi* socketApi_;

  public:
    SocketReader( SocketApi* socketApi_ );
    virtual ~SocketReader();

    std::string readToEnd( int socketFD );

  private:
    std::string getNextChunk( int socketFD );
};

#endif
