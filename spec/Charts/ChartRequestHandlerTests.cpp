#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "ChartRequestHandler.h"
#include "RunLog.h"

TEST( ChartRequestHandlerTests, Sets200Status )
{
  HttpRequest request( "", "" );

  ChartRequestHandler handler;
  HttpResponse* response = handler.handle( request );
  ASSERT_STREQ( "200 OK", response->status().c_str() );
}

//TEST( ChartRequestHandlerTests, IncludesRunLogTimeInJavascriptArray )
//{
//  Date today;
//
//
//
//  HttpRequest request( "", url.c_str() );
//
//  ChartRequestHandler handler;
//  HttpResponse* response = handler.handle( request );
//
//  ASSERT_NE( (char*) 0, strstr(response->body(), "[99999]" ));
//}

