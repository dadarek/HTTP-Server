#ifndef CHART_REQUEST_HANDLER_H
#define CHART_REQUEST_HANDLER_H

#include "HttpRequestHandler.h"
#include <vector>

class RunLog;
class Date;

class ChartRequestHandler
  : public HttpRequestHandler
{
  private:
    static const char* const STATUS_404;

  public:
    ChartRequestHandler();
    virtual ~ChartRequestHandler();

    HttpResponse* handle( HttpRequest& request );

  private:
    const RunLog* findLog( const Date&, const std::vector<RunLog>& );
};
#endif
