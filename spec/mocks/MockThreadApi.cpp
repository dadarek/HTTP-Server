#include "MockThreadApi.h"

MockThreadApi::MockThreadApi()
  : callBackFunctionPassedIn_( 0 )
{ }

MockThreadApi::~MockThreadApi()
{ }

long MockThreadApi::pthread_create(
        _opaque_pthread_t**, 
        const pthread_attr_t*, 
        void* (*callbackFunction)(void*), 
        void*
    )
{
  callBackFunctionPassedIn_ = callbackFunction;
  return 0;
}
