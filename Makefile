SDLFLAGS = `sdl-config --cflags --libs` -lSDL_image
CXXFLAGS = -O3 -std=c++1y -g -Wall --pedantic
OBJ = src/generator.o src/video.o src/background.o
TARGET = rails

$(TARGET):	$(OBJ)
	$(CXX) -o$(TARGET) $(OBJ) $(SDLFLAGS)

all:	$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
