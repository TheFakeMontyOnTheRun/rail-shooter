SDLFLAGS = `sdl-config --cflags --libs`
CCFLAGS =  -o2 -std=c99 -g -c -Wall --pedantic
CC = gcc

OBJ = src/generator.o src/video.o src/background.o

TARGET = rails

$(TARGET):	$(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(SDLFLAGS)

all:	$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
	rm src/*~
	rm *~
