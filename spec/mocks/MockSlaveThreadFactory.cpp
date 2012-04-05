#include "MockSlaveThreadFactory.h"
#include "MockSlaveThread.h"

MockSlaveThreadFactory::MockSlaveThreadFactory()
  : threadsCreated_( 0 )
  , threadsDeleted_( 0 )
  , threadsStarted_( 0 )
{ }

MockSlaveThreadFactory::~MockSlaveThreadFactory()
{ }

SlaveThread* MockSlaveThreadFactory::create()
{
  threadsCreated_++;
  return new MockSlaveThread( this );
}
