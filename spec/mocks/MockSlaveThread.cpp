#include "MockSlaveThread.h"
#include "MockSlaveThreadFactory.h"

MockSlaveThread::MockSlaveThread()
  : factory_( 0 )
  , goCalled_( false )
  , startCalled_( false )
{ }

MockSlaveThread::MockSlaveThread( MockSlaveThreadFactory* factory )
  : factory_( factory )
  , goCalled_( false )
{ }

MockSlaveThread::~MockSlaveThread()
{
  if( 0 != factory_ )
    factory_->threadsDeleted_++;
}

void MockSlaveThread::go()
{
  goCalled_ = true;
}

void MockSlaveThread::start( MasterThread& )
{
  if( 0 != factory_ )
    factory_->threadsStarted_++;
  startCalled_ = true;
}

