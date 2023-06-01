#include <iostream>
#include <math.h>
#include <ctime>
#include "pile.h"
#include "arbre.h"

using namespace std;

int main(){
    const string expression2 = "200+((15*8)/3)";
    Pile * P = new Pile();
    cout << endl;
    const string suffixe = P->gare(expression2);
    cout << endl;
    Arbre * A = new Arbre();
    A->evaluation( suffixe );
    cout << "L'expression contenue dans l'arbre est : ";
    A->afficher_Arbre();
    cout << endl; 
    cout << "L'expression correspond a l'arbre suivant : " << endl << endl;
    A->affiche();
    cout << endl << endl;

    return 0;
}