#include "MockConnectionReceiver.h"

MockConnectionReceiver::MockConnectionReceiver()
  : returnIndex_( 0 )
{ }

MockConnectionReceiver::~MockConnectionReceiver()
{ }

int MockConnectionReceiver::nextConnection()
{ 
  if( returnIndex_ == SIZE )
    throw TerminationException();

  return returnValues_[ returnIndex_++ ];
}

