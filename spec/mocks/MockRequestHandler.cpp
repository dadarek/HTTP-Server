#include "RequestHandler.h"

class MockRequestHandler
  : public RequestHandler
{
  private:
    int requestsHandled_;

  public:
    MockRequestHandler()
      : requestsHandled_( 0 )
    { }

    int requestsHandled()
    {
      return requestsHandled_;
    }
    void handle( int )
    {
      requestsHandled_++;
    }
};

