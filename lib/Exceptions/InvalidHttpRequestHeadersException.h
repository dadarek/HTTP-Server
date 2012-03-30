#ifndef INVALID_HTTP_REQUEST_HEADERS_EXCEPTION_H
#define INVALID_HTTP_REQUEST_HEADERS_EXCEPTION_H

#include <stdexcept>

class InvalidHttpRequestHeadersException
  : public std::runtime_error
{
  public:
    InvalidHttpRequestHeadersException();
    virtual ~InvalidHttpRequestHeadersException() throw();
};

#endif
