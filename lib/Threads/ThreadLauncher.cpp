#include "ThreadLauncher.h"
#include "SlaveThread.h"

#include <iostream>
void* ThreadLauncher::launch( void* thread )
{
  ( (SlaveThread*) thread )->go();
  return 0;
}
