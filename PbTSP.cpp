/*!
 * \file PbTSP.cpp
 * \brief implementation des methodes pour la classe PbTSP
 * \author GroupeB7
 * \version 0.1
 */

#include <iostream>
#include "PbTSP.hpp"
#define max 999999
#define maxV 100
using namespace std;

PbTSP::PbTSP() {
	resultat = max;
	gr = new GrapheNonOriente;
	villeDepart = 0;
	Nchemin = 0;
	nbVisite = 1;
    for (int i = 1;i < maxV;i++)
        visite[i] = false;
}

void PbTSP::setVilleDepart(int n) {
	villeDepart = n;
	visite[n] = true;
}

void PbTSP::resolution(int t) {
    int n = gr->sommetS.size();
    if (nbVisite != n)
    {
        for (int i = 1;i <= n;i++)
        {
            if (!visite[i])
            {
                visite[i] = true;
                chemin[Nchemin][nbVisite] = t;
                nbVisite++;
                resolution(i);
                nbVisite--;
                visite[i] = false;
            }
        }
    }
    else
    {
        chemin[Nchemin][nbVisite] = t;
        chemin[Nchemin][nbVisite + 1] = villeDepart;
        cout << "chemin" << Nchemin + 1<<endl;
        longueur[Nchemin] = 0;
        for (int i = 1;i <= n;i++)
        {
            longueur[Nchemin] = longueur[Nchemin] + gr->table[chemin[Nchemin][i]-1][chemin[Nchemin][i+1]-1];
            cout << chemin[Nchemin][i] << " --> ";
            chemin[Nchemin + 1][i] = chemin[Nchemin][i];
        }
        if (resultat > longueur[Nchemin])
            resultat = longueur[Nchemin];
        cout << chemin[Nchemin][n + 1] << endl;
        cout << "longeur du chemin: " << longueur[Nchemin] << endl;
        Nchemin++;
    }
}
