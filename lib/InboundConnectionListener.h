#ifndef INBOUND_CONNECTION_LISTENER_H
#define INBOUND_CONNECTION_LISTENER_H

class Socket;

class InboundConnectionListener
{
  private:
    Socket* socket_;
    int fd_;

    void closeSocket();

  public:
    InboundConnectionListener(Socket* socket, int portToListenOn );
    virtual ~InboundConnectionListener();

    int nextConnection();
};

#endif

