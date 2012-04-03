#include "MockThreadApi.h"

MockThreadApi::MockThreadApi()
  : callBackFunctionPassedIn_( 0 )
  , callBackParameterPassedIn_( 0 )
  , createReturnValue_( 0 )
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

  return createReturnValue_;
}
