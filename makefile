all: Polinomio.o main.o
	g++ Polinomio.o main.o -o poli -g
	valgrind ./poli  --track-origins=yes
Polinomio.o: Polinomio.h Polinomio.cpp
	g++ -c Polinomio.cpp -g
main.o: main.cpp
	g++ -c main.cpp -g