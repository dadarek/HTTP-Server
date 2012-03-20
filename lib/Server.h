class RequestHandler;

class Server
{
  private:
    RequestHandler* handler_;

  public:
    Server( RequestHandler* );
    virtual ~Server();

    void start();
};
