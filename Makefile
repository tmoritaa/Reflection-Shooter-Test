CXX = g++
CXXFLAGS = -g -MMD 
OBJECTSMAIN = Main.o
OBJECTSGAME = Game/Logic.o Game/ObjectHandler.o Game/GraphicsComponent.o Game/SDLWrapper.o Game/EventHandler.o Game/Game.o
OBJECTSOBJ = Objects/Object.o
OBJECTS = ${OBJECTSMAIN} ${OBJECTSOBJ} ${OBJECTSGAME} 
INCLUDE = -I./Game -I./Objects
DEPENDS = ${OBJECTS:.o=.d} 
LIBRARY = -lSDL -lSDL_image
EXEC = Shooter

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${INCLUDE} -o ${EXEC} ${OBJECTS} ${LIBRARY} 

clean:
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
