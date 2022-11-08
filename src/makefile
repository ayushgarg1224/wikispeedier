CC = g++
CXXFLAGS = -Wall
OBJS = main.o graph.o wikinode.o algorithms.o

main: ${OBJS}
	${CC} ${CXXFLAGS} -o main wikinode.o graph.o algorithms.o main.o 

main.o: main.cpp graph.h wikinode.h algorithms.h
	${CC} ${CXXFLAGS} -c main.cpp

graph.o: graph.cpp graph.h wikinode.h
	${CC} ${CXXFLAGS} -c graph.cpp

wikinode.o: wikinode.cpp wikinode.h
	${CC} ${CXXFLAGS} -c wikinode.cpp

algorithms.o: algorithms.cpp algorithms.h wikinode.h graph.h
	${CC} ${CXXFLAGS} -c algorithms.cpp

clean:
	rm -f main ${OBJS}