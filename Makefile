

CC=g++

OBJ=Window.o main.o Canvas.o
OUT=phys.exe
LFLAGS=-lmingw32 -lSDL2main -lSDL2 -Wall


all: $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(OUT) 

%.o: %.cpp 
	$(CC) -c $^

clean: 
	del *.exe *.o