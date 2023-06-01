#include <iostream>
#include <math.h>
#include <ctime>
#include "arbre.h"
#include "pile.h"

using namespace std;

Arbre::Arbre(){
    racine = NULL;
}

Arbre::~Arbre(){
    if( racine ){
        delete racine;
    }
}

bool operateur2( char c ){
	return ( c == '+' || c == '*' || c == '-' || c == '/');
}

void Arbre::evaluation( const string &suffixe){
Pile * P = new Pile();
    for( int i = 0; i < suffixe.length(); i++ ){
        if( isspace(suffixe[i])){
            continue;
        }
        if( !operateur2(suffixe[i])){
            P->empiler(new Noeud(suffixe[i]));
        }else if( operateur2(suffixe[i]) ){
            Noeud * fd = P->depiler();
            Noeud * fg = P->depiler();
            Noeud * N = new Noeud(suffixe[i],fg,fd);
            P->empiler(N);
        }
    }
    racine = P->depiler();   
}

void Arbre::afficher_Arbre( Noeud * n ){
    if( n == nullptr ){
        return;
    }
    if( n->type == 'v'){
        cout << n->val;
    }else{
        cout << "(";
        afficher_Arbre(n->fg);
        cout << n->ope;
        afficher_Arbre(n->fd);
        cout << ")";
    }
}

void Arbre::afficher_Arbre(){
    afficher_Arbre(racine);
    cout << endl;
}

void Arbre::affiche( Noeud * P ){
    int svg = 0;
    if( P != NULL ){
        if( P == racine ){
            char c = P->ope;
            cout << "                    " << c << endl;
            cout << "               _____|_____" << endl;
            cout << "               |         |" << endl;
        }else if( P->type == 'v' && P->val != 3){
            int c = P->val;
            cout << "               " << c;
        }else if( P->ope == '/'){
            char c = P->ope;
            cout << "       " << c << endl;
            cout << "                    _____|_____" << endl;
            cout << "                    |         |" << endl;
        }else if( P->ope == '*'){
            char c = P->ope;
            cout << "                    " << c << "         " << '3' << endl; // ici le 3 correspond a P->val == '3' 
            cout << "               _____|___________" << endl;
            cout << "               |               |" << endl;
        }
        affiche(P->fg);
        affiche(P->fd);
    }
}

void Arbre::affiche(){
    affiche(racine);
}
