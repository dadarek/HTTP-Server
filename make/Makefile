# Directories
GTEST_DIR = ../gtest

PROJECT_ROOT = ..

HEADERS_DIR = ${PROJECT_ROOT}/lib
HTTP_HEADERS_DIR = ${HEADERS_DIR}/Http
FILE_IO_HEADERS_DIR = ${HEADERS_DIR}/FileIO
EXCEPTIONS_HEADERS_DIR = ${HEADERS_DIR}/Exceptions

LIB_DIR = ${PROJECT_ROOT}/lib
HTTP_LIB_DIR = ${LIB_DIR}/Http
FILE_IO_LIB_DIR = ${LIB_DIR}/FileIO
EXCEPTIONS_LIB_DIR = ${LIB_DIR}/Exceptions

SPECS_DIR = ${PROJECT_ROOT}/spec
HTTP_SPECS_DIR = ${SPECS_DIR}/Http
EXCEPTIONS_SPECS_DIR = ${SPECS_DIR}/Exceptions
MOCKS_DIR = ${SPECS_DIR}/mocks


# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h


# Not sure what the difference is - Google's sample file had both of these flags.
CPPFLAGS += -I$(GTEST_DIR)/include -Wreorder
CXXFLAGS += -g -Wall -Wextra

HEADER_INCLUDES = -I${HEADERS_DIR} -I${HTTP_HEADERS_DIR} -I${MOCKS_DIR} -I${FILE_IO_HEADERS_DIR} -I${EXCEPTIONS_HEADERS_DIR}
CPP_TO_COMPILE = ${LIB_DIR}/*.cpp ${HTTP_LIB_DIR}/*.cpp ${FILE_IO_LIB_DIR}/*.cpp ${EXCEPTIONS_LIB_DIR}/*.cpp

# Targets
tests : all-tests
	./all-tests

testsn : all-tests-no-recompile
	./all-tests

clean :
	rm -f *.a *.o main *ests

main : 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread ${HEADER_INCLUDES} ${CPP_TO_COMPILE} -o main
	rm -r main.dSYM


# Builds gtest.a and gtest_main.a.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc
            
gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^



libs : 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_INCLUDES} -c ${LIB_DIR}/*.cpp

file-libs : 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_INCLUDES} -c ${FILE_IO_LIB_DIR}/*.cpp

exception-libs : 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_INCLUDES} -c ${EXCEPTIONS_LIB_DIR}/*.cpp

http-libs : 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_INCLUDES} -c ${HTTP_LIB_DIR}/*.cpp

all-libs : libs file-libs http-libs exception-libs

specs : 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_INCLUDES} -c ${SPECS_DIR}/*.cpp

http-specs : 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_INCLUDES} -c ${HTTP_SPECS_DIR}/*.cpp

exception-specs : 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_INCLUDES} -c ${EXCEPTIONS_SPECS_DIR}/*.cpp

all-specs : specs http-specs exception-specs

mocks :
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_INCLUDES} -c ${MOCKS_DIR}/*.cpp 


remove-main.o : 
	rm -f Main.o
	rm -f main.o

all-tests : all-libs mocks all-specs gtest_main.a remove-main.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread *.o gtest_main.a -o all-tests 

all-tests-no-recompile : remove-main.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread *.o gtest_main.a -o all-tests 

