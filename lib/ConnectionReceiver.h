#ifndef CONNECTION_RECEIVER_H
#define CONNECTION_RECEIVER_H

class ConnectionReceiver
{
  public:
    virtual ~ConnectionReceiver() { }

    virtual int nextConnection() = 0;
};

#endif
