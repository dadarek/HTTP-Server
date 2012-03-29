#include "gtest/gtest.h"
#include "HttpResponse.h"

TEST( HttpResponseTests, KeepsItsAssignedValue )
{
  char body[10];
  size_t size = sizeof( body );
  
  memcpy( body, "0123456789", size );

  HttpResponse response( body, size );
  int diff = memcmp( body, response.charBody(), size );
  
  ASSERT_EQ( 0, diff );
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

