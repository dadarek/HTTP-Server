#ifndef FILE_API_H
#define FILE_API_H

class FileApi
{
  public:

    virtual void open( const char* path ) = 0;

    virtual bool is_open() = 0;
    virtual bool good() = 0;

    virtual void close() = 0;
};

#endif
