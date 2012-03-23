#ifndef SOCKET_API_H
#define SOCKET_API_H

class SocketApi
{
  public:
    static const int SOCKET_EXCEPTION = 1;
    static const int BIND_EXCEPTION = 2;
    static const int ACCEPT_EXCEPTION = 3;

  public:
    SocketApi() { }
    virtual ~SocketApi() { }

    virtual int socket() = 0;
    virtual int bind( int socketFD, int portNumber ) = 0;
    virtual void listen( int socketFD ) = 0;
    virtual int accept( int socketFD ) = 0;
    virtual void close( int socketFD ) = 0;

    virtual int read( int socketFD, char* buffer, unsigned bufferSize ) = 0;
    virtual int write( int socketFD, char* buffer, unsigned length ) = 0;
};

#endif
