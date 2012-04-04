#ifndef THREAD_API_H
#define THREAD_API_H

#include "pthread.h"

class ThreadApi
{
  public:
    virtual ~ThreadApi() { }

    virtual long pthread_create( pthread_t*, const pthread_attr_t*, void* (*)(void*), void* ) = 0;

    virtual int pthread_mutex_init( pthread_mutex_t*, const pthread_mutexattr_t* ) = 0;
    virtual int pthread_mutex_destroy( pthread_mutex_t* ) = 0;
    virtual int pthread_mutex_lock( pthread_mutex_t* ) = 0;
    virtual int pthread_mutex_unlock( pthread_mutex_t* ) = 0;

    virtual int pthread_cond_init( pthread_cond_t*, pthread_condattr_t* ) = 0;
    virtual int pthread_cond_destroy( pthread_cond_t* ) = 0;
    virtual int pthread_cond_wait( pthread_cond_t*, pthread_mutex_t* ) = 0;
    virtual int pthread_cond_signal( pthread_cond_t* ) = 0;
};

#endif
