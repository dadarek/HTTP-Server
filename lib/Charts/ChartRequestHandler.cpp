#include "ChartRequestHandler.h"
#include "HttpResponse.h"
#include "HttpRequest.h"
#include "ChartUrlParser.h"
#include "RunLog.h"
#include <algorithm>
#include <sstream>

ChartRequestHandler::ChartRequestHandler()
{ }

ChartRequestHandler::~ChartRequestHandler()
{ }

HttpResponse* ChartRequestHandler::handle( HttpRequest& request )
{
  ChartUrlParser parser;
  std::vector<RunLog> logs = parser.parse( request.url() );

  Date start; start.addDays(-13);
  Date end;   end.addDays(1);


  std::stringstream buffer;
  buffer << '[';
  while(start != end)
  {
    const RunLog* log = findLog( start, logs );
    if( log != 0 )
    {
      buffer << log->timeRan();
    }
    else
    {
      buffer << '0';
    }

    start.addDays(1);
    if( start != end )
      buffer << ", ";
  }
  buffer << ']';

  const std::string& body = buffer.str();

  HttpResponse* response = new HttpResponse( body.c_str(), body.length(), "200 OK" );
  return response;
}

const RunLog* ChartRequestHandler::findLog( const Date& date, const std::vector<RunLog>& logs  )
{
  std::vector<RunLog>::const_iterator start = logs.begin();
  std::vector<RunLog>::const_iterator end = logs.end();
  while( start != end )
  {
    if( date == (*start).dateRan() )
      return &(*start);

    ++start;
  }

  return 0;
}
