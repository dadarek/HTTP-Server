#include "SystemThread.h"
#include "ThreadApi.h"

SystemThread::SystemThread( ThreadApi& threadApi )
  : threadApi_( threadApi )
{ }

SystemThread::~SystemThread()
{ }

void SystemThread::go()
{

}
