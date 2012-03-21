#include "PortListener.h"

class MockPortListener
  : public PortListener
{
  private:
    int timesToRespond_;

  public:
    MockPortListener( int timesToRespond )
      : timesToRespond_ ( timesToRespond )
    { }

    bool listen()
    {
      return (timesToRespond_--) > 0;
    }
};

