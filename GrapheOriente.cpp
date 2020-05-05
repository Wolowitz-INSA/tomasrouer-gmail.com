/*!
 * \file GrapheOriente.cpp
 * \brief implementation des methodes pour la classe GrapheOriente
 * \author GroupeB7
 * \version 0.1
 */

#include <iostream>
#include "GrapheOriente.hpp"
using namespace std;

GrapheOriente::GrapheOriente() {

}

void GrapheOriente::initialiser() {
	int i, t;
	std::vector<Arc>::iterator ita;
		for (i = 0;i < sommetS.size();i++) {
			for (t = 0;t < sommetS.size();t++) {
				table[i][t] = -1;
				for (ita = arcS.begin();ita != arcS.end();ita++) {
					if (ita->getPremierSommet() == sommetS[i] && ita->getSecondSommet() == sommetS[t])
						table[i][t] = ita->getLongueur();
				}
			}
		}
	
}

void GrapheOriente::afficher() {
	initialiser();
	std::string s = "   ";
	int i,t;
	for (i = 0;i < sommetS.size();i++) {
		s = s +" ";
		s = s + sommetS[i].getPresentation();
	}
	cout << s << endl;
	for (i = 0;i < sommetS.size();i++) {
		s = sommetS[i].getPresentation();
		for (t = 0;t < sommetS.size();t++)
		{
			if (table[i][t] == -1)
				s = s + "    ";
			else {
				s = s + " ";
				s = s + to_string(table[i][t])+ "->";
			}
	}
		cout << s << endl;
	}

}

void GrapheOriente::ajouterArc(Sommet s1, Sommet s2, int longueur)
{
	int fail = 0;
	if (s1 == s2)
		cout << "il faut que deux sommets soient differents" << endl;
	else {
		std::vector<Arc>::iterator ita;
		for (ita = arcS.begin();ita != arcS.end();ita++) {
			if (ita->getPremierSommet() == s1 && ita->getSecondSommet() == s2)
			{
				cout << "l'arc existe deja" << endl;
				fail = 1;
			}
		}
		if (fail == 0) {
			Arc a(s1, s2);
			a.setLongueur(longueur);
			arcS.push_back(a);
		}
	}
}

int GrapheOriente::nbAtcd(Sommet s) {
	int nb = 0;
	std::vector<Arc>::iterator ita;
	for (ita = arcS.begin();ita != arcS.end();ita++) {
		if (ita->getSecondSommet() == s)
			nb++;
	}
	return nb;
}
std::vector<Sommet> GrapheOriente::listeAjc(Sommet s) {

	std::vector<Sommet> ajc;
	initialiser();
	std::vector<Arc>::iterator ita;
	for (ita = arcS.begin();ita != arcS.end();ita++) {
		if (ita->getPremierSommet() == s)
			ajc.push_back(ita->getSecondSommet());
	}
	return ajc;
}
void GrapheOriente::dfsOriente(int i) {
	int j, k;
	sommetS[i].setVisite(true);
	for (j = 0;j < sommetS.size();j++)
		for (k = 0;k < sommetS.size();k++)
		{
			if (j == i && table[j][k] != -1 && !sommetS[k].getVisite())
				dfsOriente(k);

		}

};




