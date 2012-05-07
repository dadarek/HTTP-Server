#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "ChartRequestHandler.h"

TEST( ChartRequestHandlerTests, Sets200Status )
{
  HttpRequest request( "", "" );

  ChartRequestHandler handler;
  HttpResponse* response = handler.handle( request );
  ASSERT_STREQ( "200 OK", response->status().c_str() );
}
