#ifndef SOCKET_READER_H
#define SOCKET_READER_H

class SocketApi;

class SocketReader
{
  private:
    SocketApi* socketApi_;

  public:
    SocketReader( SocketApi* socketApi_ );
    virtual ~SocketReader();

    std::string readToEnd( int socketFD );
};

#endif
