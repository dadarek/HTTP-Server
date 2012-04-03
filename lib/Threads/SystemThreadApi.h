#ifndef SYSTEM_THREAD_API_H
#define SYSTEM_THREAD_API_H

#include "ThreadApi.h"

class SystemThreadApi
  : public ThreadApi
{
  public:
    SystemThreadApi();
    virtual ~SystemThreadApi();

    long pthread_create( 
        pthread_t*, 
        const pthread_attr_t*, 
        void* (*)(void*), void*
    );
};

#endif
