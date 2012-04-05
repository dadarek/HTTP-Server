#include "MockThread.h"
#include "MockSlaveThreadFactory.h"

MockThread::MockThread()
  : factory_( 0 )
  , goCalled_( false )
{ }

MockThread::MockThread( MockSlaveThreadFactory* factory )
  : factory_( factory )
  , goCalled_( false )
{ }

MockThread::~MockThread()
{
  if( 0 != factory_ )
    factory_->threadsDeleted_++;
}

void MockThread::go()
{
  goCalled_ = true;
}

void MockThread::start( MasterThread& )
{
  throw 0;
}

