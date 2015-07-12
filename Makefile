SDLFLAGS = `sdl-config --cflags --libs`
CCFLAGS =  -o2 -g -c -Wall --pedantic
CC = gcc

OBJ = src/generator.o

TARGET = generator

$(TARGET):	$(OBJ)
	$(CC) $(SDLFLAGS) -o $(TARGET) $(OBJ)

all:	$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
	rm src/*~
	rm include/*~
	rm *~
