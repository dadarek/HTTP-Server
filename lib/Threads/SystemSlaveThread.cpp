#include "SystemSlaveThread.h"
#include "ThreadApi.h"
#include "ThreadLauncher.h"
#include "ThreadStartException.h"
#include "WorkItem.h"
#include "MasterThread.h"

SystemSlaveThread::SystemSlaveThread( ThreadApi& threadApi )
  : master_( 0 )
  , threadApi_( threadApi )
{ }

SystemSlaveThread::~SystemSlaveThread()
{ }

void SystemSlaveThread::go()
{
  for(;;)
  {
    WorkItem* work = master_->next();
    work->execute();
    delete work;
  }
}

void SystemSlaveThread::start( MasterThread& master )
{
  master_ = &master;

  pthread_t identifier;
  long result = threadApi_.pthread_create( &identifier, 0, ThreadLauncher::launch, this );

  if( 0 != result )
    throw ThreadStartException();
}
