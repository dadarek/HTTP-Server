#ifndef MOCK_REQUEST_HANDLER_H
#define MOCK_REQUEST_HANDLER_H

#include "RequestHandler.h"

class MockRequestHandler
  :  public RequestHandler
{
  public:
    MockRequestHandler();
    virtual ~MockRequestHandler();

    void handle( int connection );
};

#endif
