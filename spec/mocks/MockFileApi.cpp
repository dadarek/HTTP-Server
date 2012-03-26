#include "MockFileApi.h"

MockFileApi::MockFileApi()
  : opened_( false )
  , closed_( false )
{ }

MockFileApi::~MockFileApi()
{ }

void MockFileApi::open( const char* path )
{ 
  path_ = std::string( path );
  opened_ = true;
}

bool MockFileApi::is_open()
{ throw 0; }

bool MockFileApi::good()
{ throw 0; }

void MockFileApi::close()
{
  closed_ = true;
}
