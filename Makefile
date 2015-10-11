SDLFLAGS = `sdl-config --cflags --libs` -lSDL_image
CXXFLAGS = -O3 -std=c++1y -g -Wall --pedantic
OBJ = src/RailShooter.o src/Video.o src/Background.o src/Train.o src/Car.o src/CarElement.o src/HeroTrain.o src/VillainTrain.o src/Bullet.o src/Vec2.o src/CoveredZBorCar.o src/OpenZBorCar.o src/CartCar.o src/Turret.o
TARGET = rails

$(TARGET):	$(OBJ)
	$(CXX) -o$(TARGET) $(OBJ) $(SDLFLAGS)

all:	$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
