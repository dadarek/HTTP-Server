class Server
{
  private:
    bool isStarted_;

  public:
    Server();

    void stop();
    void start();

    bool isStarted();
};
