#ifndef THREAD_START_EXCEPTION_H
#define THREAD_START_EXCEPTION_H 

#include <stdexcept>

class ThreadStartException
  : public std::runtime_error
{
  public:
    ThreadStartException();
    virtual ~ThreadStartException() throw();
};

#endif
