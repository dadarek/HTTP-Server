#include "MockFileApi.h"

MockFileApi::MockFileApi()
  : openCalled_( false )
  , closeCalled_( false )
  , isOpenCalled_( false )
  , isGoodCalled_( false )
  , isOpenReturnValue_( true )
  , timesGoodShouldReturnTrue_( 0 )
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
  return isOpenReturnValue_;
}

bool MockFileApi::good()
{
  isGoodCalled_ = true;
  return 0 < timesGoodShouldReturnTrue_--;
}

void MockFileApi::close()
{
  closeCalled_ = true;
}
