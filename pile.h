#ifndef _PILE_H_
#define _PILE_H_
#include "noeud.h"
#include <string>

using namespace std;

class Maillon{
    friend class Pile;
    Maillon * suivant;
    Noeud * adresse;

        public:
            Maillon( Noeud * N , Maillon * suivant = nullptr );
};

class Pile{
    Maillon * tete;

    public:
        Pile();
        ~Pile();
        void empiler( Noeud * N );
        bool vide();
        Noeud * depiler();
        std::string gare( const string &infixe );
        void affiche();
};

#endif
