#ifndef HTTP_SOCKET_READER_H
#define HTTP_SOCKET_READER_H

#include "SocketReader.h"

class SocketApi;

class HttpSocketReader
  : public SocketReader
{
  public:
    static const int READ_EXCEPTION = 1;

  private:
    SocketApi& socketApi_;

  public:
    HttpSocketReader( SocketApi& socketApi_ );
    virtual ~HttpSocketReader();

    std::string readToEnd( int socketFD, const char* terminator );

  private:
    std::string getNextChunk( int socketFD );
};

#endif
