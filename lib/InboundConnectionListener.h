#ifndef INBOUND_CONNECTION_LISTENER_H
#define INBOUND_CONNECTION_LISTENER_H

class SocketApi;

class InboundConnectionListener
{
  private:
    SocketApi* socketApi_;
    int fd_;

    void createSocket();
    void bindToSocket( int portToBindTo );
    void closeSocket();

  public:
    InboundConnectionListener( SocketApi* socketApi, int portToBindTo );
    virtual ~InboundConnectionListener();

    int nextConnection();
};

#endif

