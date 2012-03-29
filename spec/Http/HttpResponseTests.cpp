#include "gtest/gtest.h"
#include "HttpResponse.h"

TEST( HttpResponseTests, storesStrings )
{
  char body[10];
  size_t size = sizeof( body );
  
  memcpy( body, "0123456789", size );

  HttpResponse response( body, size );
  int diff = memcmp( body, response.charBody(), size );
  
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

  HttpResponse response( body, size );
  ASSERT_EQ( body[0], response.charBody()[0] );
  ASSERT_EQ( body[1], response.charBody()[1] );
  ASSERT_EQ( body[2], response.charBody()[2] );
  ASSERT_EQ( body[3], response.charBody()[3] );
}

TEST( HttpResponseTests, KeepsItsAssignedValue3 )
{
  std::string body = "This\nis the body\n\nyo.";
  HttpResponse response( body );
  ASSERT_EQ( body, response.body() );
}

TEST( HttpResponseTests, KeepsItsAssignedValue4 )
{
  std::string body = "Some body ... of some file ... hey!";
  HttpResponse response( body );
  ASSERT_EQ( body, response.body() );
}

