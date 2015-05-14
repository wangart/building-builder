CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = main.o Board.o Player.o Slc.o GoToTims.o printBoard.o Money.o Goose.o Needles.o DCTimsLine.o Square.o Tuition.o ABuilding.o Ownable.o Res.o Gym.o Human.o PC.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
