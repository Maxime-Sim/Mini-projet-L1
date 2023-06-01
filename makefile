tp.exe : main.o pile.o Noeud.o Arbre.o
	g++ -o tp.exe pile.o main.o Noeud.o Arbre.o

Pile.o : pile.cpp pile.h
	g++ -c pile.cpp

Arbre.o : arbre.cpp arbre.h
	g++ -c arbre.cpp

Noeud.o : noeud.cpp noeud.h
	g++ -c noeud.cpp

main.o : main.cpp
	g++ -c main.cpp
