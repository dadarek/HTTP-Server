#include "SystemSlaveThreadFactory.h"
#include "SystemThread.h"

SystemSlaveThreadFactory::SystemSlaveThreadFactory( ThreadApi& api )
  : api_( api )
{ }

SystemSlaveThreadFactory::~SystemSlaveThreadFactory()
{ }

SlaveThread* SystemSlaveThreadFactory::create()
{
  return new SystemThread( api_ );
}
