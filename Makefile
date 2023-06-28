all:
	g++ -I include -L lib -l mingw32 -l SDL2main -l SDL2 main.cpp -o main