#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

class HttpResponse
{
  private:
    char* charBody_;
    size_t bodyLength_;

  public:
    HttpResponse( const char* body, size_t bodyLength );
    virtual ~HttpResponse();

    const char* charBody();
    size_t bodyLength();
};

#endif
