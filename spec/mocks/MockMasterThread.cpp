#include "MockMasterThread.h"
#include "MockWorkItem.h"

MockMasterThread::MockMasterThread()
  : workItem_( 0 )
  , returnDummies_( false )
  , throwAfter_( 1 )
  , timesNextCalled_( 0 )
{ }

MockMasterThread::~MockMasterThread()
{ }

WorkItem* MockMasterThread::next()
{
  if( timesNextCalled_ == throwAfter_ )
    throw MockMasterThreadStopException();
  timesNextCalled_++;

  if( returnDummies_ )
    return new MockWorkItem();

  return workItem_;
}
