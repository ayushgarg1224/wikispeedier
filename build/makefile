CC = g++
CXXFLAGS = -Wall -std=c++20
OBJS = wikinode.o graph.o algorithms.o main.o
TEST_OBJS = wikinode.o graph.o algorithms.o tests.o
SDIR = ../src/
TDIR = ../tests/

main: ${OBJS}
	${CC} ${CXXFLAGS} -o main ${OBJS}

tests: ${TEST_OBJS}
	${CC} ${CXXFLAGS} -o test ${TEST_OBJS}

main.o: ${SDIR}main.cpp ${SDIR}graph.h ${SDIR}wikinode.h ${SDIR}algorithms.h
	${CC} ${CXXFLAGS} -c ${SDIR}main.cpp 

tests.o: ${TDIR}tests.cpp ${SDIR}graph.h ${SDIR}wikinode.h ${SDIR}algorithms.h
	${CC} ${CXXFLAGS} -c ${TDIR}tests.cpp

graph.o: ${SDIR}graph.cpp ${SDIR}graph.h ${SDIR}wikinode.h
	${CC} ${CXXFLAGS} -c ${SDIR}graph.cpp

wikinode.o: ${SDIR}wikinode.cpp ${SDIR}wikinode.h
	${CC} ${CXXFLAGS} -c ${SDIR}wikinode.cpp

algorithms.o: ${SDIR}algorithms.cpp ${SDIR}algorithms.h ${SDIR}wikinode.h ${SDIR}graph.h
	${CC} ${CXXFLAGS} -c ${SDIR}algorithms.cpp

clean:
	rm -f main ${OBJS} test.o

# If make isn't working just run "g++ -Wall -std=c++20 -o main ../src/main.cpp ../src/algorithms.cpp ../src/graph.cpp ../src/wikinode.cpp" from ./build