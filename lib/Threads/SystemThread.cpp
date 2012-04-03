#include "SystemThread.h"
#include "ThreadApi.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"
#include "Runnable.h"

SystemThread::SystemThread( ThreadApi& threadApi, Runnable* runnable )
  : threadApi_( threadApi )
  , runnable_( runnable )
{ }

SystemThread::~SystemThread()
{ }

void SystemThread::go()
{
  runnable_->run();
  delete runnable_;
}

void SystemThread::start()
{
  pthread_t identifier;
  long result = threadApi_.pthread_create( &identifier, 0, ThreadLauncher::launch, this );
  if( 0 != result )
    throw ThreadStartException();
}
