#include "MockMasterThread.h"

MockMasterThread::MockMasterThread()
{ }

MockMasterThread::~MockMasterThread()
{ }

WorkItem* MockMasterThread::next()
{
  throw 0;
}
