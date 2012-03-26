# Directories
GTEST_DIR = ../gtest

PROJECT_ROOT = ..
HEADERS_DIR = ${PROJECT_ROOT}/lib
LIB_DIR = ${PROJECT_ROOT}/lib
SPECS_DIR = ${PROJECT_ROOT}/spec
MOCKS_DIR = ${SPECS_DIR}/mocks

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h


# Not sure what the difference is - Google's sample file had both of these flags.
CPPFLAGS += -I$(GTEST_DIR)/include -Wreorder
CXXFLAGS += -g -Wall -Wextra

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = server icl httpHandler reader


# Targets
all : ${TESTS}

clean :
	rm -f *.a *.o main *Tests

server : ServerTests
	./ServerTests

icl : SocketConnectionReceiverTests
	./SocketConnectionReceiverTests

httpHandler : HttpConnectionHandlerTests
	./HttpConnectionHandlerTests

reader : SocketReaderTests
	./SocketReaderTests

main : 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread ${PROJECT_ROOT}/lib/*.cpp -o main
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


# YOUR tests and object files.

MockRequestHandler.o : ${MOCKS_DIR}/MockRequestHandler.cpp ${LIB_DIR}/RequestHandler.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${MOCKS_DIR}/MockRequestHandler.cpp

MockConnectionReceiver.o : ${MOCKS_DIR}/MockConnectionReceiver.cpp ${LIB_DIR}/SocketConnectionReceiver.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${MOCKS_DIR}/MockConnectionReceiver.cpp

Server.o : $(LIB_DIR)/Server.cpp $(LIB_DIR)/Server.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(LIB_DIR)/Server.cpp

ServerTests.o : $(SPECS_DIR)/ServerTests.cpp Server.o MockConnectionReceiver.o MockRequestHandler.o	
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I${HEADERS_DIR} -c $(SPECS_DIR)/ServerTests.cpp

ServerTests : MockRequestHandler.o MockConnectionReceiver.o Server.o ServerTests.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

SocketConnectionReceiver.o : ${LIB_DIR}/SocketConnectionReceiver.cpp \
	${HEADERS_DIR}/SocketConnectionReceiver.h ${HEADERS_DIR}/SocketAPI.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${LIB_DIR}/SocketConnectionReceiver.cpp

MockSocketAPI.o : ${MOCKS_DIR}/MockSocketAPI.h ${MOCKS_DIR}/MockSocketAPI.cpp ${HEADERS_DIR}/SocketAPI.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${MOCKS_DIR}/MockSocketAPI.cpp

SocketConnectionReceiverTests.o : ${SPECS_DIR}/SocketConnectionReceiverTests.cpp MockSocketAPI.o
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${SPECS_DIR}/SocketConnectionReceiverTests.cpp

SocketConnectionReceiverTests : MockSocketAPI.o SocketConnectionReceiver.o SocketConnectionReceiverTests.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@


HttpConnectionHandler.o : ${LIB_DIR}/Http/HttpConnectionHandler.cpp ${HEADERS_DIR}/Http/HttpConnectionHandler.h 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${LIB_DIR}/Http/HttpConnectionHandler.cpp

HttpConnectionHandlerTests.o : ${SPECS_DIR}/Http/HttpConnectionHandlerTests.cpp 
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${SPECS_DIR}/Http/HttpConnectionHandlerTests.cpp

HttpConnectionHandlerTests: HttpConnectionHandler.o HttpConnectionHandlerTests.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	

MockSocketReadAPI.o : ${MOCKS_DIR}/MockSocketReadAPI.h ${MOCKS_DIR}/MockSocketReadAPI.cpp ${HEADERS_DIR}/SocketAPI.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${MOCKS_DIR}/MockSocketReadAPI.cpp

SocketReader.o : ${LIB_DIR}/SocketReader.cpp \
	${HEADERS_DIR}/SocketReader.h ${HEADERS_DIR}/SocketAPI.h
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${LIB_DIR}/SocketReader.cpp

SocketReaderTests.o : ${SPECS_DIR}/SocketReaderTests.cpp MockSocketReadAPI.o
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -I${HEADERS_DIR} -c ${SPECS_DIR}/SocketReaderTests.cpp

SocketReaderTests: MockSocketReadAPI.o SocketReader.o SocketReaderTests.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
