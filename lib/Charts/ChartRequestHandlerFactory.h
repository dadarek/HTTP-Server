#ifndef CHART_REQUEST_HANDLER_FACTORY_H
#define CHART_REQUEST_HANDLER_FACTORY_H

#include "HttpRequestHandlerFactory.h"

class ChartRequestHandlerFactory
  : public HttpRequestHandlerFactory
{
  public:
    ChartRequestHandlerFactory();
    virtual ~ChartRequestHandlerFactory();

    HttpRequestHandler* createHandler( HttpRequest& request );
};

#endif
