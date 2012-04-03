#ifndef SYSTEM_THREAD_API_H
#define SYSTEM_THREAD_API_H

#include "ThreadApi.h"

class SystemThreadApi
  : public ThreadApi
{
  public:
    SystemThreadApi();
    virtual ~SystemThreadApi();
};

#endif
