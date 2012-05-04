#ifndef CHART_REQUEST_HANDLER_H
#define CHART_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"

class ChartRequestHandler
  : public HttpRequestHandler
{
  private:
    static const char* const STATUS_404;

  public:
    ChartRequestHandler();
    virtual ~ChartRequestHandler();

    HttpResponse* handle( HttpRequest& request );
};
#endif
