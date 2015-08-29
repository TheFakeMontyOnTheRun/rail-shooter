SDLFLAGS = `sdl-config --cflags --libs` -lSDL_image
CXXFLAGS = -O3 -std=c++1y -g -Wall --pedantic
OBJ = src/RailShooter.o src/Video.o src/Background.o
TARGET = rails

$(TARGET):	$(OBJ)
	$(CXX) -o$(TARGET) $(OBJ) $(SDLFLAGS)

all:	$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
