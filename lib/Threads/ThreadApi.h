#ifndef THREAD_API_H
#define THREAD_API_H

#include "pthread.h"

class ThreadApi
{
  public:
    virtual ~ThreadApi() { }

    virtual long pthread_create( 
        _opaque_pthread_t**, 
        const pthread_attr_t*, 
        void* (*)(void*), void*
    ) = 0;
};

#endif
