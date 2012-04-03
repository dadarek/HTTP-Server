#ifndef MOCK_THREAD_API_H
#define MOCK_THREAD_API_H

#include "ThreadApi.h"

class MockThreadApi
  : public ThreadApi
{
  public:
    MockThreadApi();
    virtual ~MockThreadApi();

    void go();

};

#endif
