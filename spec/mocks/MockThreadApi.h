#ifndef MOCK_THREAD_API_H
#define MOCK_THREAD_API_H

#include "ThreadApi.h"

class MockThreadApi
  : public ThreadApi
{
  public:
    MockThreadApi();
    virtual ~MockThreadApi();

    long pthread_create( 
        _opaque_pthread_t**, 
        const pthread_attr_t*, 
        void* (*)(void*),
        void*
    );
};

#endif
