#ifndef FILE_NOT_FOUND_EXCEPTION_H
#define FILE_NOT_FOUND_EXCEPTION_H

#include <stdexcept>

class FileNotFoundException
  : public std::runtime_error
{
  public:
    FileNotFoundException()
      : std::runtime_error( "File not found." )
    { }

    virtual ~FileNotFoundException() throw() { }
};

#endif
