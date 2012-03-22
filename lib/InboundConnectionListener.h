#ifndef INBOUND_CONNECTION_LISTENER_H
#define INBOUND_CONNECTION_LISTENER_H

class Socket;

class InboundConnectionListener
{
  private:
    Socket* socket_;
    int fd_;

    void createSocket();
    void bindToSocket( int portToBindTo );
    void closeSocket();

  public:
    InboundConnectionListener(Socket* socket, int portToBindTo );
    virtual ~InboundConnectionListener();

    int nextConnection();
};

#endif

