#include "SystemThread.h"
#include "ThreadApi.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"

SystemThread::SystemThread( ThreadApi& threadApi )
  : threadApi_( threadApi )
{ }

SystemThread::~SystemThread()
{ }

void SystemThread::go()
{

}

void SystemThread::start()
{
  long result = threadApi_.pthread_create( 0, 0, ThreadLauncher::launch, this );
  
  if( 0 != result )
    throw ThreadStartException();
}
