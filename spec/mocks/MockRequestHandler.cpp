#include "RequestHandler.h"

class MockRequestHandler
  : public RequestHandler
{
  public:
    int requestsHandled()
    {
      return 1;
    }
    void handle()
    {
    }
};

