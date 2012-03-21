#include "PortListener.h"

class RawPortListener
 : public PortListener
{
  private:
    int portNumber_;

  public:
    RawPortListener( int portNumber );
    bool listen();
};


