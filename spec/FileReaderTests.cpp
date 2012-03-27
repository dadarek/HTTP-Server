#include "gtest/gtest.h"
#include "FileReader.h"
#include "FileNotFoundException.h"
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

    void ensureFileOpensAs( std::ios_base::openmode mode )
    {
      readToEnd( "" );
      std::ios_base::openmode actual = mode & factory_.openmode_;
      EXPECT_EQ( mode, actual );
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

TEST_F( FileReaderTests, checksTheFileSize )
{
  readToEnd( "" );
  EXPECT_EQ( true, factory_.inspector_.sizeChecked );
}

TEST_F( FileReaderTests, callsReadWithFullFileSize )
{
  factory_.inspector_.sizeReturnValue = (size_t) 100;
  readToEnd( "" );

  EXPECT_EQ( 100, (int) factory_.inspector_.inputValueForRead );
}

TEST_F( FileReaderTests, throwsIfFileDoesNotExist )
{
  factory_.inspector_.openReturnValue = false;
  EXPECT_THROW( readToEnd( "SomePath"), FileNotFoundException );
}

TEST_F( FileReaderTests, deletesFileBeforeThrowing )
{
  factory_.inspector_.openReturnValue = false;
  try
  {
    readToEnd("");
  }
  catch( FileNotFoundException )
  { }
  ASSERT_EQ( true, factory_.inspector_.destroyed );
}

TEST_F( FileReaderTests, returnsCharactersWrittenToItsBuffer )
{
  factory_.inspector_.sizeReturnValue = (size_t) 6;
  strcpy( factory_.inspector_.buffer, "Hello" );
  EXPECT_EQ( "Hello", readToEnd( "x" ) );
}

TEST_F( FileReaderTests, opensFileForReading )
{
  ensureFileOpensAs( std::ios::in );
}

TEST_F( FileReaderTests, opensFileAtEnd )
{
  ensureFileOpensAs( std::ios::ate );
}

TEST_F( FileReaderTests, opensFileAsBinary )
{
  ensureFileOpensAs( std::ios::binary );
}

//TODO: Make sure all interfaces have a virtual dtor
//TODO: FileReader should probably return char[] instead of string
//TODO: Pull inspector out of factory.
//TODO: Use exceptions instead of ints
//TODO: Change makefile so that main depends on everything
//TODO: Can I get rid of redundant test cases? (check if read, etc)
