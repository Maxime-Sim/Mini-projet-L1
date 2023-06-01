#include <iostream>
#include <math.h>
#include <ctime>
#include "noeud.h"

using namespace std;

    // Constructeur par défaut
    Noeud::Noeud(){
        type = '\0';
        ope = '\0';
        val = 0;
        fg = nullptr;
        fd = nullptr;
    }

    // Constructeur pour un noeud contenant un opérateur
    Noeud::Noeud(char operateur, Noeud* gauche, Noeud* droite) {
        type = 'o';
        ope = operateur;
        val = 0;
        fg = gauche;
        fd = droite;
    }

    // Constructeur pour un noeud contenant une valeur
    Noeud::Noeud(float valeur ) {
        type = 'v';
        ope = '\0';
        val = valeur;
        fg = nullptr;
        fd = nullptr;
    }

    Noeud::~Noeud(){
        if( fg ){
            delete fg; 
        }else if( fd ){
            delete fd;
        }
    }

    char Noeud::getOpe(){
        return ope;
    }

    float Noeud::getVal(){
        return val;
    }
