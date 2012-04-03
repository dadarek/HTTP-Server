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
  pthread_t identifier;
  long result = threadApi_.pthread_create( &identifier, 0, ThreadLauncher::launch, this );
  if( 0 != result )
    throw ThreadStartException();
}
