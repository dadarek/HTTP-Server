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

  public:
    SocketConnectionReceiver( SocketApi& socketApi, int portToBindTo );
    virtual ~SocketConnectionReceiver();

    int nextConnection();
};

#endif

