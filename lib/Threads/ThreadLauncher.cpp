#include "ThreadLauncher.h"
#include "Thread.h"

void* ThreadLauncher::launch( void* thread )
{
  ( (Thread*) thread )->go();
  return 0;
}
