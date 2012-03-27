#ifndef INVALID_HTTP_REQUEST_HEADERS_EXCEPTION_H
#define INVALID_HTTP_REQUEST_HEADERS_EXCEPTION_H

#include <stdexcept>

class InvalidHttpRequestHeadersException
  : public std::runtime_error
{
  public:
    InvalidHttpRequestHeadersException()
      : std::runtime_error("Invalid HTTP Request headers.")
    { }
    virtual ~InvalidHttpRequestHeadersException() throw() { }
};

#endif
