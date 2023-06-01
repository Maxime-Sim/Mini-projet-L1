#include <iostream>
#include <math.h>
#include <ctime>
#include "pile.h"

using namespace std;

Maillon::Maillon( Noeud * N , Maillon * suiv ){
	suivant = suiv;
	adresse = N;
}

bool operateur( char c ){
	return ( c == '+' || c == '*' || c == '-' || c == '/');
}

bool operande( char c ){
    return( c == 'a' || c == 'b' || c == '4' || c == '3');
}

int prioriter( char M ){
	if( M == '+' || M == '-'){
		return 1;
	}else if (M == '*' || M == '/'){
		return 2;
	}
	return 0;
}

Pile::Pile(){
    tete = NULL;
}

Pile::~Pile(){
    while( this->vide() == false ){
        this->depiler();
    }
}

void Pile::empiler( Noeud * N ){
    tete = new Maillon(N,tete);
}

bool Pile::vide(){
    if( tete == NULL ){
        return true;
    }
    return false;
}

Noeud * Pile::depiler(){
    if( this->vide()){
        cout << " La pile est deja vide " << endl;
    }
    Noeud * N = tete->adresse;
    Maillon * svg = tete;
    tete = tete->suivant;
    delete svg;
    return N;
}

string Pile::gare(const string &infixe) {
    Pile * attente = new Pile();
    string expression;
    string svg;
    int cpt = 0;
    for (int i = 0; i < infixe.length(); i++) {
        if( isdigit(infixe[i])){
            int operande = infixe[i] - '0';
            while( i + 1 < infixe.length() && isdigit(infixe[i+1])){
                operande = operande * 10 + (infixe[i+1] - '0');
                i++;
            }
            this->empiler(new Noeud(operande));
        }else if( operateur(infixe[i])){
            while( !attente->vide() && operateur(attente->tete->adresse->getVal()) && (prioriter(attente->tete->adresse->getVal()) >= prioriter(infixe[i]))){
                this->empiler(attente->tete->adresse);
                attente->depiler();
            }
            attente->empiler(new Noeud(infixe[i]));
        }else if( infixe[i] == '('){
            attente->empiler(new Noeud(infixe[i]));
        }else if( infixe[i] == ')'){
            while( !attente->vide() && attente->tete->adresse->getVal() != '('){
                this->empiler(attente->tete->adresse);
                attente->depiler();
            }
            if( !attente->vide() && attente->tete->adresse->getVal() == '('){
                attente->depiler();
            }
        }
        cpt++;
    }
    cpt = cpt - 4;
    cout << endl;

    while( !attente->vide() ){
        this->empiler(attente->tete->adresse);
        attente->depiler();
    }

    while( !this->vide() ){
        char c = this->tete->adresse->getVal();
        expression += c;
        this->depiler();
    }

    int j = 0;
    for( int i = cpt-1; i != -1; i-- ){
        svg[j] = expression[i];
        j++;
    }

    cout << "L'expression suffixe corresponds a : ";
    for( int i = 0; i < cpt; i++){
        expression[i] = svg[i];
        if( !operateur(expression[i])){
            int operande = expression[i];
            cout << operande << " ";
        }else{
            cout << expression[i] << " ";
        }
    }

    return expression;
}
