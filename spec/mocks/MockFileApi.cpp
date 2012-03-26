#include "MockFileApi.h"

MockFileApi::MockFileApi()
  : openCalled_( false )
  , closeCalled_( false )
  , isOpenCalled_( false )
  , isGoodCalled_( false )
{ }

MockFileApi::~MockFileApi()
{ }

void MockFileApi::open( const char* path )
{ 
  path_ = std::string( path );
  openCalled_ = true;
}

bool MockFileApi::is_open()
{
  isOpenCalled_ = true;
  return false;
}

bool MockFileApi::good()
{
  isGoodCalled_ = true;
  return false;
}

void MockFileApi::close()
{
  closeCalled_ = true;
}
