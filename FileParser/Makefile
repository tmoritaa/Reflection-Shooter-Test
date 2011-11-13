CXX = g++
CXXFLAGS = -g -MMD 
OBJECTSMAIN = FileParser.o FileParserTest.o
OBJECTS = ${OBJECTSMAIN} 
DEPENDS = ${OBJECTS:.o=.d} 
EXEC = FileParserTest

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${INCLUDE} -o ${EXEC} ${OBJECTS} ${LIBRARY} 

clean:
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
