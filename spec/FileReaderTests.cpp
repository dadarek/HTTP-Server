#include "gtest/gtest.h"
#include "FileReader.h"
#include "mocks/MockFileApi.h"

class FileReaderTests
  : public ::testing::Test
{
  protected:

};

TEST_F( FileReaderTests, Compiles )  
{
  MockFileApi fileApi;
  FileReader fileReader( fileApi );
}

