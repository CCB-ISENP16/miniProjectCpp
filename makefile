STB_INCLUDE_PATH = ./extern/stb

CFLAGS = -std=c++11 -g -I$(STB_INCLUDE_PATH) -Isrc
LDFLAGS =

APP = FigureCreator
OBJ = miniproj.o Drawing.o Figure.o FigRect.o FigSquare.o FigCross.o Segment.o Point.o Menu.o


$(APP): $(OBJ)
	g++ $(CFLAGS) -o $(APP) $(OBJ) $(LDFLAGS)

miniproj.o: miniproj.cpp
	g++ $(CFLAGS) -c miniproj.cpp $(LDFLAGS)

Drawing.o: src/Drawing.cpp
	g++ $(CFLAGS) -c src/Drawing.cpp $(LDFLAGS)

Figure.o: src/Figure.cpp
	g++ $(CFLAGS) -c src/Figure.cpp $(LDFLAGS)

FigRect.o: src/FigRect.cpp
	g++ $(CFLAGS) -c src/FigRect.cpp $(LDFLAGS)

FigCross.o: src/FigCross.cpp
	g++ $(CFLAGS) -c src/FigCross.cpp $(LDFLAGS)

Segment.o: src/Segment.cpp
	g++ $(CFLAGS) -c src/Segment.cpp $(LDFLAGS)

FigSquare.o: src/FigSquare.cpp
	g++ $(CFLAGS) -c src/FigSquare.cpp $(LDFLAGS)

Point.o: src/Point.cpp
	g++ $(CFLAGS) -c src/Point.cpp $(LDFLAGS)

Menu.o: src/Menu.cpp
	g++ $(CFLAGS) -c src/Menu.cpp $(LDFLAGS)


.PHONY: test clean

clean:
	rm -f $(APP)
	rm -f *.o
