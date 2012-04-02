#include "gtest/gtest.h"
#include "HttpResponse.h"

TEST( HttpResponseTests, storesStrings )
{
  char body[10];
  size_t size = sizeof( body );
  
  memcpy( body, "0123456789", size );

  HttpResponse response( body, size, "" );
  int diff = memcmp( body, response.body(), size );
  
  ASSERT_EQ( 0, diff );
}

TEST( HttpResponseTests, storesBinary )
{
  char body[4];
  size_t size = sizeof( body );
  
  body[0] = 0;
  body[1] = 15;
  body[2] = '\0';
  body[3] = 255;

  HttpResponse response( body, size, "" );
  ASSERT_EQ( body[0], response.body()[0] );
  ASSERT_EQ( body[1], response.body()[1] );
  ASSERT_EQ( body[2], response.body()[2] );
  ASSERT_EQ( body[3], response.body()[3] );
}

TEST( HttpResponseTests, remembersTheResponseSize )
{
  HttpResponse response( "something", 9, "" );
  ASSERT_EQ( 9, (int) response.bodyLength() );
}

TEST( HttpResponseTests, remembersResponseCode )
{
  std::string status(" 200 OK ");
  HttpResponse response( "", 0, status );
  ASSERT_EQ( status, response.status() );
}
