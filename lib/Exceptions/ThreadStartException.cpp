#include "ThreadStartException.h"

ThreadStartException::ThreadStartException()
  : std::runtime_error( "Failed to start thread." )
{ }

ThreadStartException::~ThreadStartException() throw()
{ }
