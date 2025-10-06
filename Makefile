all: main.out

main.out: main.o utilitaire.o
	g++ -o main.out main.o utilitaire.o

main.o: main.cpp
	g++ -c main.cpp

utilitaire.o: utilitaire.cpp
	g++ -c utilitaire.cpp

.PHONY: all clean

clean:
	rm -f *.o main.out
