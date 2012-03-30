#include "InvalidHttpRequestHeadersException.h"

InvalidHttpRequestHeadersException::InvalidHttpRequestHeadersException()
  : std::runtime_error("Invalid HTTP Request headers.")
{ }

InvalidHttpRequestHeadersException::~InvalidHttpRequestHeadersException() throw()
{ }

