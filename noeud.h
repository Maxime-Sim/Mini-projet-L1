#ifndef _NOEUD_H_
#define _NOEUD_H_
#include <iostream>

class Noeud{ // Noeud de l'arbre
    friend class Arbre;
    char type; // "o" pour operateur et "v" pour valeur
    char ope; // operation
    float val; // operande
    Noeud * fg, *fd;
    
    public:
        Noeud();
        Noeud( float valeur );
        Noeud( char operateur, Noeud * g , Noeud * d );
        Noeud( Noeud * adr , Noeud * suiv );
        char getOpe();
        float getVal();
        ~Noeud();   
};

#endif