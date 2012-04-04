#include "gtest/gtest.h"
#include "ThreadPool.h"
#include "MockThreadApi.h"

TEST( ThreadPoolTests, Compiles )
{
  MockThreadApi api;
  ThreadPool pool( api );
}
