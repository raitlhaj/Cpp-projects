CC=g++
CCFLAGS= -c
LDFLAGS= -lm
EXE=ex02
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
$(EXE):$(OBJ)
	$(CC) -o $(EXE) $^ $(LDFLAGS)
%.o:%.cpp
	$(CC) $(CCFLAGS) $<
clean:
	rm $(OBJ) $(EXE)

