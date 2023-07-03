all:
	g++ -I SDL/include -L SDL/lib -l mingw32 -l SDL2main -l SDL2 -l SDL2_ttf main.cpp src/*.cpp -o main