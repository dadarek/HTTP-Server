#include "SystemThreadApi.h"

SystemThreadApi::SystemThreadApi()
{ }

SystemThreadApi::~SystemThreadApi()
{ }

long SystemThreadApi::pthread_create(
        pthread_t* threadPointer,
        const pthread_attr_t* attributes, 
        void* (*function)(void*) ,
        void* functionParameter
    )
{
 return ::pthread_create( threadPointer, attributes, function, functionParameter );
}
