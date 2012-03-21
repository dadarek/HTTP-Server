#ifndef SERVER_H
#define SERVER_H

class RequestHandler;
class PortListener;

class Server
{
  private:
    RequestHandler* handler_;
    PortListener* listener_;

  public:
    Server( PortListener*, RequestHandler* );
    virtual ~Server();

    void start();
};

#endif
