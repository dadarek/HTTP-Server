#include "SystemThreadApi.h"

SystemThreadApi::SystemThreadApi()
{ }

SystemThreadApi::~SystemThreadApi()
{ }

long SystemThreadApi::pthread_create(
        pthread_t* threadPointer,
        const pthread_attr_t* attributes, 
        void* (*function)(void*) ,
        void* functionParameter
    )
{
 return ::pthread_create( threadPointer, attributes, function, functionParameter );
}

int SystemThreadApi::pthread_mutex_init( pthread_mutex_t* mutex, const pthread_mutexattr_t* attributes )
{
  return ::pthread_mutex_init( mutex, attributes );
}

int SystemThreadApi::pthread_mutex_destroy( pthread_mutex_t* mutex )
{
  return ::pthread_mutex_destroy( mutex );
}

int SystemThreadApi::pthread_mutex_lock( pthread_mutex_t* mutex )
{
  return ::pthread_mutex_lock( mutex );
}

int SystemThreadApi::pthread_mutex_unlock( pthread_mutex_t* mutex )
{
  return ::pthread_mutex_unlock( mutex );
}

int SystemThreadApi::pthread_cond_init( pthread_cond_t* condition, pthread_condattr_t* attributes )
{
  return ::pthread_cond_init( condition, attributes );
}

int SystemThreadApi::pthread_cond_destroy( pthread_cond_t* condition )
{
  return ::pthread_cond_destroy( condition );
}

int SystemThreadApi::pthread_cond_wait( pthread_cond_t* condition, pthread_mutex_t* mutex )
{
  return ::pthread_cond_wait( condition, mutex );
}

int SystemThreadApi::pthread_cond_signal( pthread_cond_t* condition )
{
  return ::pthread_cond_signal( condition );
}

