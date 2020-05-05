/*!
 * \file Arc.cpp
 * \brief implementation des methodes pour la classe Arc
 * \author GroupeB7
 * \version 0.1
 */

#include <iostream>
#include <string>
#include "Arc.hpp"
using namespace std;

Arc::Arc(Sommet s1, Sommet s2) {
	if(s1 == s2)
		cout << "ce n¡¯est pas un arc d¡¯un graphe simple" << endl;
	else {
		sommet1 = s1;
		sommet2 = s2;
		longueur = 0;
	}
}

Sommet Arc::getPremierSommet() {
	return sommet1;
}

Sommet Arc::getSecondSommet() {
	return sommet2;
}

int Arc::getLongueur() {
	return longueur;
}

void Arc::setLongueur(int l) {
	if (l < 0)
		cout << "il faut que la longueur soit positive" << endl;
	else longueur = l;
}



