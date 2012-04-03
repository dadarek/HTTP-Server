#ifndef MOCK_THREAD_API_H
#define MOCK_THREAD_API_H

#include "ThreadApi.h"

class MockThreadApi
  : public ThreadApi
{
  public:
    void* (*callBackFunctionPassedIn_)(void*);
    void* callBackParameterPassedIn_;
    long createReturnValue_;

    MockThreadApi();
    virtual ~MockThreadApi();

    long pthread_create( 
        pthread_t*, 
        const pthread_attr_t*, 
        void* (*)(void*),
        void*
    );
};

#endif
