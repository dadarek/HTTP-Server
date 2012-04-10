#include "MockThreadApi.h"
#include <stdexcept>

MockThreadApi::MockThreadApi()
  : callBackFunctionPassedIn_( 0 )
  , callBackParameterPassedIn_( 0 )
  , createReturnValue_( 0 )
  , isLocked_( false )
  , isSignaled_( false )
  , inputTo_mutexInit_( 0 )
  , inputTo_mutexDestroy_( 0 )
  , inputTo_mutexLock_( 0 )
  , inputTo_mutexUnlock_( 0 )
  , inputTo_condInit_( 0 )
  , inputTo_condDestroy_( 0 )
  , inputTo_condSignal_( 0 )
  , inputTo_condWait_( 0 )
  , times_condWait_called_( 0 )
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
  if( 0 == createReturnValue_ )
  {
    callBackFunctionPassedIn_ = callbackFunction;
    callBackParameterPassedIn_ = callbackParameter;

    (*threadId) = (pthread_t) 50;

    (*callbackFunction) ( callbackParameter );
  }

  return createReturnValue_;
}

int MockThreadApi::pthread_mutex_init( pthread_mutex_t* mutex, const pthread_mutexattr_t* )
{
  inputTo_mutexInit_ = mutex;
  return 0;
}

int MockThreadApi::pthread_mutex_destroy( pthread_mutex_t* mutex )
{
  inputTo_mutexDestroy_ = mutex;
  return 0;
}

int MockThreadApi::pthread_mutex_lock( pthread_mutex_t* mutex )
{
  if( isLocked_ )
    throw std::runtime_error( "Can't lock an already locked mutex." );

  isLocked_ = true;
  inputTo_mutexLock_ = mutex;
  return 0;
}

int MockThreadApi::pthread_mutex_unlock( pthread_mutex_t* mutex )
{
  if( !isLocked_ )
    throw std::runtime_error( "Can't unlock a mutex that wasn't locked." );

  isLocked_ = false;
  inputTo_mutexUnlock_ = mutex;
  return 0;
}

int MockThreadApi::pthread_cond_init( pthread_cond_t* condition, pthread_condattr_t* )
{
  inputTo_condInit_ = condition;
  return 0;
}

int MockThreadApi::pthread_cond_destroy( pthread_cond_t* condition )
{
  inputTo_condDestroy_ = condition;
  return 0;
}

int MockThreadApi::pthread_cond_wait( pthread_cond_t* condition, pthread_mutex_t* mutex )
{
  inputTo_condWait_ = condition;
  inputTo_condWait_mutex_ = mutex;
  times_condWait_called_++;
  return 0;
}

int MockThreadApi::pthread_cond_signal( pthread_cond_t* condition )
{
  if( !isLocked_ )
    throw std::runtime_error( "Can't signal a condition without locking a mutex.");

  isSignaled_ = true;
  inputTo_condSignal_ = condition;
  return 0;
}

bool MockThreadApi::mutexWasInitialized()
{
  return (void*) 0 != inputTo_mutexInit_;
}

bool MockThreadApi::mutexWasDestroyed()
{
  return inputTo_mutexInit_ == inputTo_mutexDestroy_;
}

bool MockThreadApi::conditionVariableWasInitialized()
{
  return (void*) 0 != inputTo_condInit_;
}

bool MockThreadApi::conditionVariableWasDestroyed()
{
  return inputTo_condInit_ == inputTo_condDestroy_;
}

bool MockThreadApi::mutexWasLocked()
{
  return inputTo_mutexInit_ == inputTo_mutexLock_;
}

bool MockThreadApi::mutexWasUnlocked()
{
  return inputTo_mutexInit_ == inputTo_mutexUnlock_;
}

bool MockThreadApi::conditionVariableWasSignalled()
{
  return inputTo_condInit_ == inputTo_condSignal_;
}
