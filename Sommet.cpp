/*!
 * \file Sommet.cpp
 * \brief implementation des methodes pour la classe Sommet
 * \author GroupeB7
 * \version 0.1
 */

#include <iostream>
#include <string>
#include "Sommet.hpp"
using namespace std;

Sommet::Sommet() {
	valeur = rand();
	visite = false;
	presentation = "NOM";
}
Sommet::Sommet(std::string nom) {
	valeur = rand();
	visite = false;
	if (nom.size()>0) {
		if (nom.size() == 1)
			presentation = " " + nom + " ";
		else if (nom.size() == 2)
			presentation = " " + nom;
		else if (nom.size() == 3)
			presentation = nom;
		else{
			cout << "longueur maximal du nom est 3" << endl;
			presentation = "NOM";
		}
	}
	else {
		cout << "le nom ne doit pas etre vide" << endl;
		presentation = "NOM";
	}
}

int Sommet::getValeur() {
	return valeur;
}

void Sommet::setValeur(int nb) {
	if (nb < 0)
		cout << "il faut que le poids soit positif" << endl;
	else valeur = nb;
}

std::string Sommet::getPresentation() {
	return presentation;
}

void Sommet::setPresentation(std::string nom) {
	if (nom.size() > 0) {
		if (nom.size()<= 3)
			presentation = nom;
		else {
			cout << "longueur maximal du nom est 3" << endl;
		}
	}
	else {
		cout << "le nom ne doit pas etre vide" << endl;
	}
}

bool Sommet::getVisite() {
	return visite;
}

void Sommet::setVisite(bool v) {
	visite = v;
}

void Sommet::operator=(const Sommet& s) {
	setPresentation(s.presentation);
	setValeur(s.valeur);
}

bool Sommet::operator==(const Sommet& s){

	if (presentation != s.presentation || valeur != s.valeur)
		return false;
	else return true;
}
