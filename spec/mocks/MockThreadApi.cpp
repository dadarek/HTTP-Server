#include "MockThreadApi.h"

MockThreadApi::MockThreadApi()
{ }

MockThreadApi::~MockThreadApi()
{ }

long MockThreadApi::pthread_create(
        _opaque_pthread_t**, 
        const pthread_attr_t*, 
        void* (*)(void*), 
        void*
    )
{
  throw 0;
}
