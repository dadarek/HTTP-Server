#ifndef MOCK_REQUEST_HANDLER_H
#define MOCK_REQUEST_HANDLER_H

#include "RequestHandler.h"

class MockRequestHandler
  :  public RequestHandler
{
  public:
    int index_;
    int connectionsHandled_[ 4 ];

    MockRequestHandler();
    virtual ~MockRequestHandler();

    void handle( int connection );
};

#endif
