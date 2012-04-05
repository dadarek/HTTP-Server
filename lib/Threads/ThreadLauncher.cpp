#include "ThreadLauncher.h"
#include "Thread.h"

#include <iostream>
void* ThreadLauncher::launch( void* thread )
{
  ( (Thread*) thread )->go();
  return 0;
}
