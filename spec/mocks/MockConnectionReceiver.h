#ifndef MOCK_INBOUND_CONNECTION_LISTENER
#define MOCK_INBOUND_CONNECTION_LISTENER

#include "ConnectionReceiver.h"
#include "MockSocketApi.h"

class MockConnectionReceiver
  : public ConnectionReceiver
{
  private:
    static const int SIZE = 4;
    int returnIndex_;

  public:
    int returnValues_[ SIZE ];

    MockConnectionReceiver();
    ~MockConnectionReceiver();

    int nextConnection();
};

class TerminationException{ };

#endif

