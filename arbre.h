#ifndef _ARBRE_H_
#define _ARBRE_H_
#include "noeud.h"

using namespace std;

class Arbre
{
    Noeud * racine;

    public:
        Arbre();
        ~Arbre();
        void evaluation( const string &suffixe );
        void afficher_Arbre(Noeud * n);
        void afficher_Arbre();
        void affiche();
        void affiche( Noeud * N);
};

#endif
