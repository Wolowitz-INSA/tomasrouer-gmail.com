/*!
 * \file PbTriTopologique.cpp
 * \brief implementation des methodes pour la classe PbTriTopologique
 * \author GroupeB7
 * \version 0.1
 */

#include <iostream>
#include "PbTriTopologique.hpp"
using namespace std;

PbTriTopologique::PbTriTopologique() {
	gr = new GrapheOriente();
}

void PbTriTopologique::resolution() {
	int j;
	bool faisable = true;
	int nb = gr->sommetS.size();
	for (j = 0;j <nb;j++)
	{
		if (gr->nbAtcd(gr->sommetS[j]) == 0)
			candidat.push_back(j);
	}
	int etape = 0;
	while (resultat.size()<nb)
	{
		etape++;
		cout << "etape" << etape<< endl;
		gr->afficher();
		if (candidat.empty()) {
			faisable = false;
			cout << "Ce probleme n'est pas resoluble" << endl;
			break;
		}
		else {
			int i = candidat[0];
			resultat.push_back(gr->sommetS[i]);
			gr->supprimerSommet(i + 1);
			candidat.clear();
			for (j = 0;j < gr->sommetS.size();j++)
			{
				if (gr->nbAtcd(gr->sommetS[j]) == 0)
					candidat.push_back(j);
			}
		}
	}
	if (faisable) {
		cout << "resultat: " << endl;
		for (j = 0;j < nb;j++) {
			cout << " " << resultat[j].getPresentation();
		}
		cout << " " << endl;
	}
}