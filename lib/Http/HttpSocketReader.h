#ifndef HTTP_SOCKET_READER_H
#define HTTP_SOCKET_READER_H

#include "SocketReader.h"

class SocketApi;

class HttpSocketReader
  : public SocketReader
{
  private:
    static const char* const STREAM_TERMINATOR;
    SocketApi& socketApi_;

  public:
    HttpSocketReader( SocketApi& socketApi_ );
    virtual ~HttpSocketReader();

    std::string readToEnd( int socketFD );

  private:
    std::string getNextChunk( int socketFD );
};

#endif
