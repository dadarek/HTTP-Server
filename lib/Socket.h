#ifndef SOCKET_H
#define SOCKET_H

class Socket
{
  public:
    Socket() { }
    virtual ~Socket() { }

    virtual int socket() = 0;
    virtual int bind( int socketFD ) = 0;
    virtual void listen( int socketFD ) = 0;
    virtual int accept( int socketFD ) = 0;
    virtual void close( int socketFD ) = 0;
};

#endif
