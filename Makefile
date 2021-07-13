

CC=g++

OBJ=Window.o main.o Canvas.o
OUT=phys.exe
LFLAGS=-lSDL2main -lSDL2 -Wall

##-lmingw32 


all: $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(OUT) 

%.o: %.cpp 
	$(CC) -c $^

#for windows
clean: 
	del *.exe *.o

#for linux

clear:
	rm *.exe *.o