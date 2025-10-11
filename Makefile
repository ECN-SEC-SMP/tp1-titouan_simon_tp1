all: main.out

main.out: main.o utilitaire.o lexique.o
	g++ -o main.out main.o utilitaire.o lexique.o

main.o: main.cpp
	g++ -c main.cpp

utilitaire.o: utilitaire.cpp
	g++ -c utilitaire.cpp

lexique.o: lexique.cpp
	g++ -c lexique.cpp
.PHONY: all clean

clean:
	rm -f *.o main.out
