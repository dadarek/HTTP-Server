#include "SystemThread.h"
#include "ThreadApi.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"
#include "Runnable.h"
#include "WorkItem.h"
#include "MasterThread.h"

SystemThread::SystemThread( ThreadApi& threadApi )
  : master_( 0 )
  , threadApi_( threadApi )
{ }

SystemThread::~SystemThread()
{ }

void SystemThread::go()
{
  WorkItem* work = master_->next();
  work->execute();
  delete work;
}

void SystemThread::start( Runnable* runnable )
{
  runnable_ = runnable;

  pthread_t identifier;
  long result = threadApi_.pthread_create( &identifier, 0, ThreadLauncher::launch, this );
  if( 0 != result )
    throw ThreadStartException();
}

void SystemThread::start( MasterThread& master )
{
  master_ = &master;

  pthread_t identifier;
  long result = threadApi_.pthread_create( &identifier, 0, ThreadLauncher::launch, this );
  if( 0 != result )
    throw ThreadStartException();
}
