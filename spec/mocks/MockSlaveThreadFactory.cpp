#include "MockSlaveThreadFactory.h"
#include "MockThread.h"

MockSlaveThreadFactory::MockSlaveThreadFactory()
  : threadsCreated_( 0 )
  , threadsDeleted_( 0 )
{ }

MockSlaveThreadFactory::~MockSlaveThreadFactory()
{ }

SlaveThread* MockSlaveThreadFactory::create()
{
  threadsCreated_++;
  return new MockThread( this );
}
