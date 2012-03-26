#include "gtest/gtest.h"
#include "FileReader.h"
#include "mocks/MockFileApi.h"

class FileReaderTests
  : public ::testing::Test
{
  protected:
    MockFileApi fileApi_;
    FileReader reader_;

    FileReaderTests()
      : reader_( fileApi_ )
    { }

    std::string readToEnd( std::string path )
    {
      return reader_.readToEnd( path );
    }
};

TEST_F( FileReaderTests, opensRequestedFile )  
{
  std::string path( "SomePath" );
  readToEnd( path );

  EXPECT_EQ( true, fileApi_.openCalled_ );
  EXPECT_EQ( path, fileApi_.path_ );
}

TEST_F( FileReaderTests, closesFile )  
{
  std::string path( "SomePath" );
  readToEnd( "" );

  EXPECT_EQ( true, fileApi_.closeCalled_ );
}

TEST_F( FileReaderTests, checksIfOpenAndGood )  
{
  readToEnd( "" );
  EXPECT_EQ( true, fileApi_.isOpenCalled_ );
  EXPECT_EQ( true, fileApi_.isGoodCalled_ );
}


TEST_F( FileReaderTests, throwsIfFileDoesNotExist )
{
  fileApi_.isOpenReturnValue_ = false;
  EXPECT_THROW( readToEnd( "SomePath"), int );
}

TEST_F( FileReaderTests, ReadsUntilGoodReturnsFalse )
{
  fileApi_.timesGoodShouldReturnTrue_ = 5;
  readToEnd( "Some Path" );

  ASSERT_EQ( -1, fileApi_.timesGoodShouldReturnTrue_ );
}
