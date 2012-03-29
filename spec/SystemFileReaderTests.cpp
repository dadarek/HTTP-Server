#include "gtest/gtest.h"
#include "SystemFileReader.h"
#include "FileNotFoundException.h"
#include "mocks/MockFileFactory.h"

class SystemFileReaderTests
  : public ::testing::Test
{
  protected:
    MockFileInspector inspector_;
    MockFileFactory factory_;
    SystemFileReader reader_;

    SystemFileReaderTests()
      : inspector_()
      , factory_( inspector_ )
      , reader_( factory_ )
    { }

    std::string readToEnd( std::string path )
    {
      return reader_.readToEnd( path );
    }

    void ensureFileOpensAs( std::ios_base::openmode mode )
    {
      readToEnd( "" );
      std::ios_base::openmode actual = mode & factory_.openmode_;
      EXPECT_EQ( mode, actual );
    }
};

TEST_F( SystemFileReaderTests, opensRequestedFile )  
{
  std::string path( "SomePath" );
  readToEnd( path );

  EXPECT_EQ( true, factory_.openCalled_ );
  EXPECT_EQ( path, factory_.path_ );
}

TEST_F( SystemFileReaderTests, closesFile )  
{
  std::string path( "SomePath" );
  readToEnd( "" );
  EXPECT_EQ( true, inspector_.closed );
}

TEST_F( SystemFileReaderTests, destroysFile )  
{
  readToEnd( "" );
  EXPECT_EQ( true, inspector_.destroyed );
}

TEST_F( SystemFileReaderTests, checksIfFileOpened )
{
  readToEnd( "" );
  EXPECT_EQ( true, inspector_.checkedIfOpen );
}

TEST_F( SystemFileReaderTests, checksTheFileSize )
{
  readToEnd( "" );
  EXPECT_EQ( true, inspector_.sizeChecked );
}

TEST_F( SystemFileReaderTests, callsReadWithFullFileSize )
{
  inspector_.sizeReturnValue = (size_t) 100;
  readToEnd( "" );

  EXPECT_EQ( 100, (int) inspector_.inputValueForRead );
}

TEST_F( SystemFileReaderTests, throwsIfFileDoesNotExist )
{
  inspector_.openReturnValue = false;
  EXPECT_THROW( readToEnd( "SomePath"), FileNotFoundException );
}

TEST_F( SystemFileReaderTests, deletesFileBeforeThrowing )
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

TEST_F( SystemFileReaderTests, returnsCharactersWrittenToItsBuffer )
{
  inspector_.sizeReturnValue = (size_t) 6;
  strcpy( inspector_.buffer, "Hello" );
  EXPECT_EQ( "Hello", readToEnd( "x" ) );
}

TEST_F( SystemFileReaderTests, opensFileForReading )
{
  ensureFileOpensAs( std::ios::in );
}

TEST_F( SystemFileReaderTests, opensFileAtEnd )
{
  ensureFileOpensAs( std::ios::ate );
}

TEST_F( SystemFileReaderTests, opensFileAsBinary )
{
  ensureFileOpensAs( std::ios::binary );
}

