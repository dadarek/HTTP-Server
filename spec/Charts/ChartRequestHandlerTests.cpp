#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "ChartRequestHandler.h"
#include "RunLog.h"
#include "UrlUtilities.h"

TEST( ChartRequestHandlerTests, Sets200Status )
{
  HttpRequest request( "", "" );

  ChartRequestHandler handler;
  HttpResponse* response = handler.handle( request );
  ASSERT_STREQ( "200 OK", response->status().c_str() );
}

TEST( ChartRequestHandlerTests, IncludesRunLogTimeInJavascriptArray )
{
  Date today;
  char url[100];
  sprintf( url, "[\"date_ran\":\"%d-%02d-%02d\",\"time_ran\":\"99999\"]", today.year(), today.month(), today.day() );

  const std::string& encoded = UrlUtilities::encode( url );

  HttpRequest request( "", encoded );

  ChartRequestHandler handler;
  HttpResponse* response = handler.handle( request );

  ASSERT_NE( (char*) 0, strstr(response->body(), "[99999]" ));
}

