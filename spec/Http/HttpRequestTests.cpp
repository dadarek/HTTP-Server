#include "gtest/gtest.h"
#include "Http/HttpRequest.h"

TEST( HttpRequestTests, KeepsItsAssignedValue )
{
  std::string url = "/Some/Url.html";
  HttpRequest request( url );
  ASSERT_EQ( url, request.url() );
}

TEST( HttpRequestTests, KeepsItsAssignedValue2 )
{
  std::string url = "/AnotherUrl.html";
  HttpRequest request( url );
  ASSERT_EQ( url, request.url() );
}

