CC = g++
CXXFLAGS = -Wall
OBJS = wikinode.o graph.o algorithms.o main.o
SDIR = ../src/

main: ${OBJS}
	${CC} ${CXXFLAGS} -o main ${OBJS}

main.o: ${SDIR}main.cpp ${SDIR}graph.h ${SDIR}wikinode.h ${SDIR}algorithms.h
	${CC} ${CXXFLAGS} -c ${SDIR}main.cpp 

graph.o: ${SDIR}graph.cpp ${SDIR}graph.h ${SDIR}wikinode.h
	${CC} ${CXXFLAGS} -c ${SDIR}graph.cpp

wikinode.o: ${SDIR}wikinode.cpp ${SDIR}wikinode.h
	${CC} ${CXXFLAGS} -c ${SDIR}wikinode.cpp

algorithms.o: ${SDIR}algorithms.cpp ${SDIR}algorithms.h ${SDIR}wikinode.h ${SDIR}graph.h
	${CC} ${CXXFLAGS} -c ${SDIR}algorithms.cpp

clean:
	rm -f main ${OBJS}

# If make isn't working just run "g++ -Wall -o main ../src/main.cpp ../src/algorithms.cpp ../src/graph.cpp ../src/wikinode.cpp" from ./build