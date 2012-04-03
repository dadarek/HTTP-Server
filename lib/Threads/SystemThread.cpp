#include "SystemThread.h"
#include "ThreadApi.h"
#include "ThreadLauncher.h"

SystemThread::SystemThread( ThreadApi& threadApi )
  : threadApi_( threadApi )
{ }

SystemThread::~SystemThread()
{ }

void SystemThread::go()
{

}

void SystemThread::start()
{
  threadApi_.pthread_create( 0, 0, ThreadLauncher::launch, 0 );
}
