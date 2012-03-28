#ifndef INBOUND_CONNECTION_LISTENER_H
#define INBOUND_CONNECTION_LISTENER_H

#include "ConnectionReceiver.h"

class SocketApi;

class SocketConnectionReceiver
  : public ConnectionReceiver
{
  private:
    SocketApi& socketApi_;
    int fd_;

    void createSocket();
    void bindToSocket( int portToBindTo );
    void closeSocket();

    struct sockaddr_in createBindAddress( int portToBindTo );

  public:
    SocketConnectionReceiver( SocketApi& socketApi, int portToBindTo );
    virtual ~SocketConnectionReceiver();

    int nextConnection();
};

#endif

