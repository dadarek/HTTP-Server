#include "MockConnectionReceiver.h"

MockConnectionReceiver::MockConnectionReceiver()
{ }

MockConnectionReceiver::~MockConnectionReceiver()
{ }

int MockConnectionReceiver::nextConnection()
{ throw 1; }
