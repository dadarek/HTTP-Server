#include "SystemSlaveThreadFactory.h"
#include "SystemSlaveThread.h"

SystemSlaveThreadFactory::SystemSlaveThreadFactory( ThreadApi& api )
  : api_( api )
{ }

SystemSlaveThreadFactory::~SystemSlaveThreadFactory()
{ }

SlaveThread* SystemSlaveThreadFactory::create()
{
  return new SystemSlaveThread( api_ );
}
