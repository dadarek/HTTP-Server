#include "MockThreadApi.h"
#include "Thread.h"

MockThreadApi::MockThreadApi()
  : callBackFunctionPassedIn_( 0 )
  , callBackParameterPassedIn_( 0 )
  , createReturnValue_( 0 )
  , in_mutexInit_( 0 )
  , in_mutexDestroy_( 0 )
  , in_mutexLock_( 0 )
  , in_mutexUnlock_( 0 )
  , in_condInit_( 0 )
  , in_condDestroy_( 0 )
  , in_condSignal_( 0 )
  , in_condWait_( 0 )
{ }

MockThreadApi::~MockThreadApi()
{ }

long MockThreadApi::pthread_create(
        pthread_t* threadId, 
        const pthread_attr_t*, 
        void* (*callbackFunction)(void*), 
        void* callbackParameter
    )
{
  callBackFunctionPassedIn_ = callbackFunction;
  callBackParameterPassedIn_ = callbackParameter;

  (*threadId) = (pthread_t) 50;

  (*callbackFunction) ( callbackParameter );
  return createReturnValue_;
}

int MockThreadApi::pthread_mutex_init( pthread_mutex_t* mutex, const pthread_mutexattr_t* attributes )
{
  in_mutexInit_ = mutex;
  return 0;
}

int MockThreadApi::pthread_mutex_destroy( pthread_mutex_t* mutex )
{
  in_mutexDestroy_ = mutex;
  return 0;
}

int MockThreadApi::pthread_mutex_lock( pthread_mutex_t* mutex )
{
  in_mutexLock_ = mutex;
  return 0;
}

int MockThreadApi::pthread_mutex_unlock( pthread_mutex_t* mutex )
{
  throw 0;
}

int MockThreadApi::pthread_cond_init( pthread_cond_t* condition, pthread_condattr_t* attributes )
{
  in_condInit_ = condition;
  return 0;
}

int MockThreadApi::pthread_cond_destroy( pthread_cond_t* condition )
{
  in_condDestroy_ = condition;
  return 0;
}

int MockThreadApi::pthread_cond_wait( pthread_cond_t* condition, pthread_mutex_t* mutex )
{
  throw 0;
}

int MockThreadApi::pthread_cond_signal( pthread_cond_t* condition )
{
  throw 0;
}

