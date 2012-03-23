#ifndef SERVER_H
#define SERVER_H

class RequestHandler;
class ConnectionReceiver;

class Server
{
  private:
    RequestHandler& handler_;
    ConnectionReceiver& receiver_;

  public:
    Server( ConnectionReceiver&, RequestHandler& );
    virtual ~Server();

    void start();
};

#endif
