#include "gtest/gtest.h"
#include "HttpResponse.h"

TEST( HttpResponseTests, KeepsItsAssignedValue )
{
  std::string body = "This\nis the body\n\nyo.";
  HttpResponse response( body );
  ASSERT_EQ( body, response.body() );
}

TEST( HttpResponseTests, KeepsItsAssignedValue2 )
{
  std::string body = "Some body ... of some file ... hey!";
  HttpResponse response( body );
  ASSERT_EQ( body, response.body() );
}

