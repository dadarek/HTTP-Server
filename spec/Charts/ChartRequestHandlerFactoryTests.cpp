#include "gtest/gtest.h"
#include "ChartRequestHandlerFactory.h"
#include "ChartRequestHandler.h"
#include "HttpRequest.h"

TEST( ChartRequestHandlerFactoryTests, compiles )
{
  ChartRequestHandlerFactory factory;
  HttpRequest request( "", "" );
  HttpRequestHandler* handler = factory.createHandler( request );
  ASSERT_NE( (void*) 0, handler );
  ASSERT_EQ( handler, dynamic_cast < ChartRequestHandler* > ( handler ) );
}
