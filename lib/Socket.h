#ifndef SOCKET_H
#define SOCKET_H

class Socket
{
  public:
    static const int SOCKET_EXCEPTION = 1;
    static const int BIND_EXCEPTION = 1;

  public:
    Socket() { }
    virtual ~Socket() { }

    virtual int socket() = 0;
    virtual int bind( int socketFD, int portNumber ) = 0;
    virtual void listen( int socketFD ) = 0;
    virtual int accept( int socketFD ) = 0;
    virtual void close( int socketFD ) = 0;
};

#endif
