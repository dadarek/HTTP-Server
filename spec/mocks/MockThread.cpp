#include "MockThread.h"

MockThread::MockThread()
  : goCalled_( false )
{ }

MockThread::~MockThread()
{
}

void MockThread::go()
{
  goCalled_ = true;
}

void MockThread::start( Runnable* )
{
  throw 0;
}
