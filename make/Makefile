# Directories
GTEST_DIR = ../gtest

PROJECT_ROOT = ..

HEADERS_DIR = ${PROJECT_ROOT}/lib
HTTP_HEADERS_DIR = ${HEADERS_DIR}/Http

LIB_DIR = ${PROJECT_ROOT}/lib
HTTP_LIB_DIR = ${LIB_DIR}/Http

SPECS_DIR = ${PROJECT_ROOT}/spec
HTTP_SPECS_DIR = ${SPECS_DIR}/Http
MOCKS_DIR = ${SPECS_DIR}/mocks

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h


# Not sure what the difference is - Google's sample file had both of these flags.
CPPFLAGS += -I$(GTEST_DIR)/include -Wreorder
CXXFLAGS += -g -Wall -Wextra

# Targets
tests : all-tests
	./all-tests

clean :
	rm -f *.a *.o main *ests

main : 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread -I${HEADERS_DIR} -I${HTTP_HEADERS_DIR} ${LIB_DIR}/*.cpp ${HTTP_LIB_DIR}/*.cpp -o main
	rm -r main.dSYM
	./main


# Builds gtest.a and gtest_main.a.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


HEADER_LOCATIONS = -I${HEADERS_DIR} -I${HTTP_HEADERS_DIR} -I${MOCKS_DIR}
FILES_TO_COMPILE =  ${LIB_DIR}/*.cpp ${HTTP_LIB_DIR}/*.cpp ${MOCKS_DIR}/*.cpp ${SPECS_DIR}/*.cpp ${HTTP_SPECS_DIR}/*.cpp

all-objects : 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${HEADER_LOCATIONS} -c ${FILES_TO_COMPILE}

all-tests : all-objects gtest_main.a
	rm main.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread *.o gtest_main.a -o all-tests 

