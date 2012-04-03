#include "MockRunnable.h"

MockRunnable::MockRunnable()
  : ran_( false )
{ }

MockRunnable::~MockRunnable()
{ }

void MockRunnable::run()
{
  ran_ = true;
}
