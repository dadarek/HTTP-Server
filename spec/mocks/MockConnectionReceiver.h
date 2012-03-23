#ifndef MOCK_INBOUND_CONNECTION_LISTENER
#define MOCK_INBOUND_CONNECTION_LISTENER

#include "ConnectionReceiver.h"
#include "MockSocketApi.h"

class MockConnectionReceiver
  : public ConnectionReceiver
{
  public:
    MockConnectionReceiver();
    ~MockConnectionReceiver();

    int nextConnection();
};


#endif

