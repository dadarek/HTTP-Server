#include "MockRunnable.h"

MockRunnable::MockRunnable( MockRunnableInspector& inspector )
  : inspector_( inspector )
{ }

MockRunnable::~MockRunnable()
{
  inspector_.deleted = true;
}

void MockRunnable::run()
{
  inspector_.ran = true;
}
