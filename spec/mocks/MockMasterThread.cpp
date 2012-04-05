#include "MockMasterThread.h"

MockMasterThread::MockMasterThread()
  : workItem_( 0 )
{ }

MockMasterThread::~MockMasterThread()
{ }

WorkItem* MockMasterThread::next()
{
  return workItem_;
}
