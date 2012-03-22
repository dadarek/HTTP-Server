#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

class RequestHandler
{
  public:
    virtual void handle( int connection ) = 0;
};

#endif

