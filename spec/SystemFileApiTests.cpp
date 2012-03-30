#include "gtest/gtest.h"
#include "SystemFileApi.h"
#include "FileNotFoundException.h"
#include "mocks/MockFileFactory.h"

class SystemFileApiTests
  : public ::testing::Test
{
  protected:
    MockFileInspector inspector_;
    MockFileFactory factory_;
    SystemFileApi fileApi_;

    SystemFileApiTests()
      : inspector_()
      , factory_( inspector_ )
      , fileApi_( factory_ )
    { }

    std::string readToEnd( std::string path )
    {
      return fileApi_.readToEnd( path );
    }

    void ensureFileOpensAs( std::ios_base::openmode mode )
    {
      readToEnd( "" );
      std::ios_base::openmode actual = mode & factory_.openmode_;
      EXPECT_EQ( mode, actual );
    }
};

TEST_F( SystemFileApiTests, opensRequestedFile )  
{
  std::string path( "SomePath" );
  readToEnd( path );

  EXPECT_EQ( true, factory_.openCalled_ );
  EXPECT_EQ( path, factory_.path_ );
}

TEST_F( SystemFileApiTests, closesFile )  
{
  std::string path( "SomePath" );
  readToEnd( "" );
  EXPECT_EQ( true, inspector_.closed );
}

TEST_F( SystemFileApiTests, destroysFile )  
{
  readToEnd( "" );
  EXPECT_EQ( true, inspector_.destroyed );
}

TEST_F( SystemFileApiTests, checksIfFileOpened )
{
  readToEnd( "" );
  EXPECT_EQ( true, inspector_.checkedIfOpen );
}

TEST_F( SystemFileApiTests, checksTheFileSize )
{
  readToEnd( "" );
  EXPECT_EQ( true, inspector_.sizeChecked );
}

TEST_F( SystemFileApiTests, callsReadWithFullFileSize )
{
  inspector_.sizeReturnValue = (size_t) 100;
  readToEnd( "" );

  EXPECT_EQ( 100, (int) inspector_.inputValueForRead );
}

TEST_F( SystemFileApiTests, throwsIfFileDoesNotExist )
{
  inspector_.openReturnValue = false;
  EXPECT_THROW( readToEnd( "SomePath"), FileNotFoundException );
}

TEST_F( SystemFileApiTests, deletesFileBeforeThrowing )
{
  inspector_.openReturnValue = false;
  try
  {
    readToEnd("");
  }
  catch( FileNotFoundException )
  { }
  ASSERT_EQ( true, inspector_.destroyed );
}

TEST_F( SystemFileApiTests, returnsCharactersWrittenToItsBuffer )
{
  inspector_.sizeReturnValue = (size_t) 6;
  strcpy( inspector_.buffer, "Hello" );
  EXPECT_EQ( "Hello", readToEnd( "x" ) );
}

TEST_F( SystemFileApiTests, opensFileForReading )
{
  ensureFileOpensAs( std::ios::in );
}

TEST_F( SystemFileApiTests, opensFileAtEnd )
{
  ensureFileOpensAs( std::ios::ate );
}

TEST_F( SystemFileApiTests, opensFileAsBinary )
{
  ensureFileOpensAs( std::ios::binary );
}

TEST_F( SystemFileApiTests, existsOpensRequestedFile )
{
  std::string path( "my-file.txt");
  fileApi_.exists( path );
  EXPECT_EQ( path, factory_.path_ );
}

TEST_F( SystemFileApiTests, existsChecksIfFileOpened )
{
  std::string path( "my-file.txt");
  fileApi_.exists( path );
  EXPECT_EQ( true, inspector_.checkedIfOpen );
}

