#include "MockFileApi.h"

MockFileApi::MockFileApi()
{ }

MockFileApi::~MockFileApi()
{ }

void MockFileApi::open( const char* location )
{ throw 0; }

bool MockFileApi::is_open()
{ throw 0; }

bool MockFileApi::good()
{ throw 0; }

void MockFileApi::close()
{ throw 0; }

