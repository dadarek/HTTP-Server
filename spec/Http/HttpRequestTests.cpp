#include "gtest/gtest.h"
#include "HttpRequest.h"

TEST( HttpRequestTests, KeepsItsAssignedValues )
{
  std::string httpMethod = "POST";
  std::string url = "/Some/Url.html";
  
  HttpRequest request( httpMethod, url );

  ASSERT_EQ( httpMethod, request.method() );
  ASSERT_EQ( url, request.url() );
}

TEST( HttpRequestTests, KeepsItsAssignedValue2 )
{
  std::string httpMethod = "GET";
  std::string url = "/AnotherUrl.html";

  HttpRequest request( httpMethod, url );

  ASSERT_EQ( httpMethod, request.method() );
  ASSERT_EQ( url, request.url() );
}

