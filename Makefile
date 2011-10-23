CXX = g++
CXXFLAGS = -g -MMD 
OBJECTSMAIN = Main.o
OBJECTSGAME = Game/GraphicsComponent.o Game/SDLWrapper.o Game/EventHandler.o Game/Game.o
OBJECTS = ${OBJECTSMAIN} ${OBJECTSGAME}
DEPENDS = ${OBJECTS:.o=.d} 
INCLUDE = -I ./Game/
LIBRARY = -lSDL
EXEC = Shooter

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} -o ${EXEC} ${OBJECTS} ${LIBRARY} 

clean:
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
