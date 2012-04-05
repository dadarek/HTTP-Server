#include "MockThreadFactory.h"
#include "MockThread.h"

MockThreadFactory::MockThreadFactory()
  : threadsCreated_( 0 )
  , threadsDeleted_( 0 )
{ }

MockThreadFactory::~MockThreadFactory()
{ }

SlaveThread* MockThreadFactory::create()
{
  threadsCreated_++;
  return new MockThread( this );
}
