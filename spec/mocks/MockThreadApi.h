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

    bool isLocked_;

    pthread_mutex_t* in_mutexInit_;
    pthread_mutex_t* in_mutexDestroy_;
    pthread_mutex_t* in_mutexLock_;
    pthread_mutex_t* in_mutexUnlock_;

    pthread_cond_t* in_condInit_;
    pthread_cond_t* in_condDestroy_;
    pthread_cond_t* in_condSignal_;
    pthread_cond_t* in_condWait_;

    MockThreadApi();
    virtual ~MockThreadApi();

    long pthread_create( pthread_t*, const pthread_attr_t*, void* (*)(void*), void* );

    int pthread_mutex_init( pthread_mutex_t*, const pthread_mutexattr_t* );
    int pthread_mutex_destroy( pthread_mutex_t* );
    int pthread_mutex_lock( pthread_mutex_t* );
    int pthread_mutex_unlock( pthread_mutex_t* );

    int pthread_cond_init( pthread_cond_t*, pthread_condattr_t* );
    int pthread_cond_destroy( pthread_cond_t* );
    int pthread_cond_wait( pthread_cond_t*, pthread_mutex_t* );
    int pthread_cond_signal( pthread_cond_t* );
};

#endif
