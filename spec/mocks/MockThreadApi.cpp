#include "MockThreadApi.h"
#include "Thread.h"

MockThreadApi::MockThreadApi()
  : callBackFunctionPassedIn_( 0 )
  , callBackParameterPassedIn_( 0 )
  , createReturnValue_( 0 )
  , mutexInit_mutex_input_( 0 )
  , mutexDestroy_mutex_input_( 0 )
  , condInit_cond_input_( 0 )
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
  mutexInit_mutex_input_ = mutex;
  return 0;
}

int MockThreadApi::pthread_mutex_destroy( pthread_mutex_t* mutex )
{
  mutexDestroy_mutex_input_ = mutex;
  return 0;
}

int MockThreadApi::pthread_mutex_lock( pthread_mutex_t* mutex )
{
  throw 0;
}

int MockThreadApi::pthread_mutex_unlock( pthread_mutex_t* mutex )
{
  throw 0;
}

int MockThreadApi::pthread_cond_init( pthread_cond_t* condition, pthread_condattr_t* attributes )
{
  condInit_cond_input_ = condition;
  return 0;
}

int MockThreadApi::pthread_cond_destroy( pthread_cond_t* condition )
{
  throw 0;
}

int MockThreadApi::pthread_cond_wait( pthread_cond_t* condition, pthread_mutex_t* mutex )
{
  throw 0;
}

int MockThreadApi::pthread_cond_signal( pthread_cond_t* condition )
{
  throw 0;
}

