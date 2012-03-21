#ifndef INBOUND_CONNECTION_LISTENER_H
#define INBOUND_CONNECTION_LISTENER_H

class Socket;

class InboundConnectionListener
{
  private:
    Socket* socket_;

  public:
    InboundConnectionListener(Socket* socket, int portToListenOn );
    virtual ~InboundConnectionListener();
};

#endif

