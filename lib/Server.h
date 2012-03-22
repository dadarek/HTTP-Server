#ifndef SERVER_H
#define SERVER_H

class RequestHandler;
class InboundConnectionListener;

class Server
{
  private:
    RequestHandler* handler_;
    InboundConnectionListener* listener_;

  public:
    Server( InboundConnectionListener*, RequestHandler* );
    virtual ~Server();

    void start();
};

#endif
