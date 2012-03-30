#ifndef FILE_NOT_FOUND_EXCEPTION_H
#define FILE_NOT_FOUND_EXCEPTION_H

#include <stdexcept>

class FileNotFoundException
  : public std::runtime_error
{
  public:
    FileNotFoundException();
    virtual ~FileNotFoundException() throw();
};

#endif
