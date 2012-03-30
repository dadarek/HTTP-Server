#ifndef HTTP_REQUEST_FILE_HANDLER_H
#define HTTP_REQUEST_FILE_HANDLER_H

#include <string>
#include "HttpRequestHandler.h"

class FileApi;

class HttpRequestFileHandler
  : public HttpRequestHandler
{
  private:
    std::string basePath_;
    FileApi& fileApi_;

  public:
    HttpRequestFileHandler( std::string basePath, FileApi& fileApi );
    virtual ~HttpRequestFileHandler();

    HttpResponse* handle( HttpRequest& request);

};
#endif
