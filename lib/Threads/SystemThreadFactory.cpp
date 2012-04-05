#include "SystemThreadFactory.h"
#include "SystemThread.h"

SystemThreadFactory::SystemThreadFactory( ThreadApi& api )
  : api_( api )
{ }

SystemThreadFactory::~SystemThreadFactory()
{ }

SlaveThread* SystemThreadFactory::create()
{
  return new SystemThread( api_ );
}
