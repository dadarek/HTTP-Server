#include "SystemThread.h"
#include "ThreadApi.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"
#include "Runnable.h"

SystemThread::SystemThread( ThreadApi& threadApi )
  : master_( 0 )
  , threadApi_( threadApi )
{ }

SystemThread::~SystemThread()
{ }

void SystemThread::go()
{
}

void SystemThread::start( Runnable* runnable )
{
  runnable_ = runnable;

  pthread_t identifier;
  long result = threadApi_.pthread_create( &identifier, 0, ThreadLauncher::launch, this );
  if( 0 != result )
    throw ThreadStartException();
}

void SystemThread::start( MasterThread& )
{
  pthread_t identifier;
  long result = threadApi_.pthread_create( &identifier, 0, ThreadLauncher::launch, this );
  if( 0 != result )
    throw ThreadStartException();
}
