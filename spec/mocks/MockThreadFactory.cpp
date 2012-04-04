#include "MockThreadFactory.h"
#include "MockThread.h"

MockThreadFactory::MockThreadFactory()
  : threadsCreated_( 0 )
{ }

MockThreadFactory::~MockThreadFactory()
{ }

Thread* MockThreadFactory::create()
{
  threadsCreated_++;
  return new MockThread();
}
