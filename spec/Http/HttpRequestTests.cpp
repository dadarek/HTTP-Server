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

TEST( HttpRequestTests, KeepsItsBody )
{
  const char* body = "Hello there"; 
  size_t length = strlen( body );

  HttpRequest request( "", "" );
  request.setBody( body, length );


  int diff = memcmp( body, request.body(), length );
  ASSERT_EQ( 0, diff );
  ASSERT_EQ( length, request.bodyLength() );
}

// sets body only once
