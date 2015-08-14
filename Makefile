SDLFLAGS = `sdl-config --cflags --libs` -lSDL_image
CCFLAGS =  -O3 -std=c99 -g -Wall --pedantic
CC = g++
OBJ = src/generator.o src/video.o src/background.o
TARGET = rails

$(TARGET):	$(OBJ)
	$(CC) $(CCFLAGS) -o$(TARGET) $(OBJ) $(SDLFLAGS)

all:	$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
	rm src/*~
	rm *~
