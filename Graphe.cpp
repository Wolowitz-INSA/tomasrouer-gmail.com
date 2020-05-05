/*!
 * \file Graphe.cpp
 * \brief implementation des methodes pour la classe Graphe
 * \author GroupeB7
 * \version 0.1
 */

#include <iostream>
#include <string>
#include "Graphe.hpp"
using namespace std;

Graphe::Graphe() {
	cout << "construction du graphe reussie" << endl;
}





void Graphe::ajouterSommet(Sommet s) {
	sommetS.push_back(s);
}

void Graphe::supprimerSommet(int i) {
	if (i > sommetS.size()) cout << "il n'existe pas ieme sommet" << endl;
	else {
		
		std::vector<Arc>::iterator ita;
		for (ita = arcS.begin();ita != arcS.end();) {
			if (ita->getPremierSommet() == sommetS[i-1] || ita->getSecondSommet() == sommetS[i-1]) 
				ita = arcS.erase(ita);
			else ++ita;
				}
		sommetS.erase(sommetS.begin() + i - 1);
	}
}



void Graphe::supprimerArc(int i) 
{
	if (i > arcS.size()) cout << "il n'existe pas "<< i <<"eme arc" << endl;
	else arcS.erase(arcS.begin() + i - 1);
}

bool Graphe::connexe() {
	initialiser();
	int i;
	for (i = 0;i < sommetS.size();i++)
		sommetS[i].setVisite(false);
	dfs(0);
	for (i = 0;i < sommetS.size();i++) {
		if (!sommetS[i].getVisite())
			return false;
	}
	return true;
}

void Graphe::dfs(int i) {
	int j, k;
	sommetS[i].setVisite(true);
	for (j=0;j<sommetS.size();j++)
		for (k = 0;k < sommetS.size();k++)
		{
			if (j == i && table[j][k] != -1 && !sommetS[k].getVisite())
				dfs(k);
			if (k == i && table[j][k] != -1 && !sommetS[j].getVisite())
				dfs(j);
		}

}

std::vector<Sommet> Graphe::listeAccessible(int i) {
	std::vector<Sommet> acc;
	initialiser();
	int t;
	for (t = 0;t < sommetS.size();t++)
		sommetS[i].setVisite(false);
	dfsOriente(0);
	for (t = 0;t < sommetS.size();t++) {
		if (sommetS[i].getVisite())
			acc.push_back(sommetS[i]);
	}
	return acc;

}





