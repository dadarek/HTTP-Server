#include "gtest/gtest.h"
#include "FileReader.h"
#include "mocks/MockFileFactory.h"

class FileReaderTests
  : public ::testing::Test
{
  protected:
    MockFileFactory factory_;
    FileReader reader_;

    FileReaderTests()
      : reader_( factory_ )
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

  EXPECT_EQ( true, factory_.openCalled_ );
  EXPECT_EQ( path, factory_.path_ );
}

TEST_F( FileReaderTests, closesFile )  
{
  std::string path( "SomePath" );
  readToEnd( "" );
  EXPECT_EQ( true, factory_.inspector_.closed );
}

TEST_F( FileReaderTests, destroysFile )  
{
  readToEnd( "" );
  EXPECT_EQ( true, factory_.inspector_.destroyed );
}

TEST_F( FileReaderTests, checksIfFileOpened )
{
  readToEnd( "" );
  EXPECT_EQ( true, factory_.inspector_.checkedIfOpen );
}

TEST_F( FileReaderTests, throwsIfFileDoesNotExist )
{
  factory_.inspector_.openReturnValue = false;
  EXPECT_THROW( readToEnd( "SomePath"), int );
}

//TODO: Check if file was deleted
//TODO: Check open flags
//TODO: Make sure it reads file in full
//TODO: Make sure all interfaces have a virtual dtor
