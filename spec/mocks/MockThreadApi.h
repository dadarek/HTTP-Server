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
    bool isSignaled_;

    pthread_mutex_t* inputTo_mutexInit_;
    pthread_mutex_t* inputTo_mutexDestroy_;
    pthread_mutex_t* inputTo_mutexLock_;
    pthread_mutex_t* inputTo_mutexUnlock_;

    pthread_cond_t* inputTo_condInit_;
    pthread_cond_t* inputTo_condDestroy_;
    pthread_cond_t* inputTo_condSignal_;
    pthread_cond_t* inputTo_condWait_;
    pthread_mutex_t* inputTo_condWait_mutex_;

    unsigned times_condWait_called_;

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

    bool mutexWasInitialized();
    bool mutexWasDestroyed();

    bool conditionVariableWasInitialized();
    bool conditionVariableWasDestroyed();

    bool mutexWasLocked();
    bool mutexWasUnlocked();

    bool conditionVariableWasSignalled();
};

#endif
