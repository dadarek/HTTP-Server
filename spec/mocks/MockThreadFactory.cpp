#include "MockThreadFactory.h"
#include "MockThread.h"

MockThreadFactory::MockThreadFactory()
{ }

MockThreadFactory::~MockThreadFactory()
{ }

Thread* MockThreadFactory::create()
{
  return new MockThread();
}
