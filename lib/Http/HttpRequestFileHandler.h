#ifndef HTTP_REQUEST_FILE_HANDLER_H
#define HTTP_REQUEST_FILE_HANDLER_H

#include "HttpRequestHandler.h"
#include "FileReader.h"

class HttpRequestFileHandler
  : public HttpRequestHandler
{
  private:
    std::string basePath_;
    FileReader& reader_;

  public:
    HttpRequestFileHandler( std::string basePath, FileReader& reader );
    virtual ~HttpRequestFileHandler();

    HttpResponse* handle( HttpRequest& request);

};
#endif
