#include "ChartRequestHandler.h"
#include "HttpResponse.h"
#include "HttpRequest.h"
#include "ChartUrlParser.h"
#include "RunLog.h"

ChartRequestHandler::ChartRequestHandler()
{ }

ChartRequestHandler::~ChartRequestHandler()
{ }

HttpResponse* ChartRequestHandler::handle( HttpRequest& request )
{
  ChartUrlParser parser;
  std::vector<RunLog> logs = parser.parse( request.url() );

  const char* body;
  if( 0 == logs.size() )
  {
    body = "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]";
  }
  else
  {
    body = "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99999]";
  }

  HttpResponse* response = new HttpResponse( body, strlen(body), "200 OK" );
  return response;
}
