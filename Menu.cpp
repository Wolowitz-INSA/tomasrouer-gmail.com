/*!
 * \file Menu.cpp
 * \brief le main qui permet l'utlisateur de faire des manipulations
 * \author GroupeB7
 * \version 0.1
 */

#include <iostream>
#include "PbTSP.hpp"
#include "PbTriTopologique.hpp"
#include <limits>
using namespace std;


void grapheManipulation(Graphe* g)
{
	int choix2 = 0;
	while (choix2 != 9)
	{
		cout << "1.Ajouter un sommet" << endl;
		cout << "2.Supprimer un sommet" << endl;
		cout << "3.Ajouter un arc" << endl;
		cout << "4.Supprimer un arc" << endl;
		cout << "5.Determinier la connexite" << endl;
		cout << "6.Afficher le graphe" << endl;
		cout << "7.Calculer nombre d'antecedantes d'un sommet" << endl;
		cout << "8.Afficher les ajacents d'un sommet" << endl;
		cout << "9.Quitter" << endl;
		cout << "votre choix:";
		cin >> choix2;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (choix2) {
		case 9: break;
		case 1: {
			string nom;
			cout << "Le nom du sommet:(longueur maximale du nom :3)";
			cin >> nom;
			Sommet* s = new Sommet(nom);
			g->ajouterSommet(*s);
			break;
		}
		case 2:
		{
			for (int i = 0;i < g->sommetS.size();i++)
				cout << i + 1 << g->sommetS[i].getPresentation() << endl;
			cout << "Quel sommet? (Mettez l'entier avant le nom du sommet)";
			int sas;
			cin >> sas;
			g->supprimerSommet(sas);
			break;
		}
		case 3:
		{
			int s1, s2,l;
			for (int i = 0;i < g->sommetS.size();i++)
				cout << i + 1 << g->sommetS[i].getPresentation() << endl;
			cout << "Premier sommet? (Mettez l'entier avant le nom du sommet)";
			cin >> s1;
			cout << "Deuxieme sommet? (Mettez l'entier avant le nom du sommet)";
			cin >> s2;
			cout << "longeur de l'arc ?";
			cin >> l;
			if (s1 > g->sommetS.size() || s2 > g->sommetS.size())
				cout << "ERREUR" << endl;
			else g->ajouterArc(g->sommetS[s1 - 1], g->sommetS[s2 - 1], l);
			break;
		}
		case 4:
		{
			int aas;
			for (int i = 0;i < g->arcS.size();i++)
				cout << i + 1 << g->arcS[i].getPremierSommet().getPresentation() << g->arcS[i].getSecondSommet().getPresentation() << endl;
			cout << "Quel arc? (Mettez l'entier avant les noms des sommet representant l'arc)";
			cin >> aas;
			g->supprimerArc(aas);
			break;
		}
		case 5:
		{
			bool con = g->connexe();
			if(con)
				cout << "Le graphe est connexe" << endl;
			else cout << "Le graphe n'est pas connexe" << endl;
			break;
		}
		case 6:
		{
			g->afficher();
			break;
		}
		case 7:
		{
			for (int i = 0;i < g->sommetS.size();i++)
				cout << i + 1 << g->sommetS[i].getPresentation() << endl;
			cout << "Quel sommet?(Mettez l'entier avant le nom du sommet)";
			int s;
			cin >> s;
			if (s > g->sommetS.size())
				cout << "ERREUR" << endl;
			else cout << "nombre atcd :" << g->nbAtcd(g->sommetS[s - 1])<<endl;
			break;
		}
		case 8:
		{
			for (int i = 0;i < g->sommetS.size();i++)
				cout << i + 1 << g->sommetS[i].getPresentation() << endl;
			cout << "Quel sommet?(Mettez l'entier avant le nom du sommet)";
			int s;
			cin >> s;
			if (s > g->sommetS.size())
				cout << "ERREUR" << endl;
			else {
				vector<Sommet> ajc = g->listeAjc(g->sommetS[s - 1]);
				for (int i = 0;i < ajc.size();i++)
				{
					cout << ajc[i].getPresentation();
				}
				cout << "" << endl;
			}
			break;
		}
		default:
		{
			cout << "Commande invalide" << endl;
			break;
		}
		}
	}

}
int main(int argc, char* argv[]) {
	cout << "Projet Graphe" << endl;
	int choix1 = 0;
	Graphe* g;
	while (choix1 <= 0 || choix1 >= 6)
	{
		cout << "1.Manipulation du graphe oriente" << endl;
		cout << "2.Manipulation du graphe non-oriente" << endl;
		cout << "3.Resolution d'un probleme Tri-Topologique" << endl;
		cout << "4.Resolution d'un probleme du voyageur de commerce" << endl;
		cout << "5.Quitter" << endl;
		cout << "votre choix:";
		cin >> choix1;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (choix1) {
		case 5: return 0;
		case 1: 
		{
			GrapheOriente go;
			g = &go;
			grapheManipulation(g);
			break;
		}
		case 2:
		{
			GrapheNonOriente gn;
			g = &gn;
			grapheManipulation(g);
			break;
		}
		case 3: {
			PbTriTopologique* p = new PbTriTopologique();
			int choixtt = 0;
			while (choixtt != 4) {
				cout << "1.Ajouter une tache" << endl;
				cout << "2.Ajouter une Relation" << endl;
				cout << "3.Resoudre le probleme" << endl;
				cout << "4.Quitter" << endl;
				cout << "votre choix:";
				cin >> choixtt;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				switch (choixtt) {
				case 4: return 0;
				case 1: {
					string nom;
					cout << "Le nom de la tache:";
					cin >> nom;
					Sommet* s = new Sommet(nom);
					p->gr->ajouterSommet(*s);
					break;
				}
				case 2: {
					int s1, s2;
					for (int i = 0;i < p->gr->sommetS.size();i++)
						cout << i + 1 << p->gr->sommetS[i].getPresentation() << endl;
					cout << "Premiere tache?(Mettez l'entier avant le nom de la tache)";
					cin >> s1;
					cout << "Deuxieme tache?(Mettez l'entier avant le nom de la tache)";
					cin >> s2;
					if (s1 > p->gr->sommetS.size() || s2 > p->gr->sommetS.size())
						cout << "ERREUR" << endl;
					else p->gr->ajouterArc(p->gr->sommetS[s1 - 1], p->gr->sommetS[s2 - 1], 0);
					break;
				}
				case 3: {
					p->resolution();
					return 0;
				}
				default:
				{
					cout << "Commande invalide" << endl;
					break;
				}
				}
			}
		}
		case 4: {
			PbTSP* p = new PbTSP();
			int i,t,nb;
			cout << "Nombre de villes?(<=8,sinon tres couteux)";
			cin >> nb;
			for (i = 1;i <= nb;i++) {
				Sommet* s = new Sommet(to_string(i));
				p->gr->ajouterSommet(*s);
			}
			for (i = 1;i <= nb;i++) {
				for (t = i+1;t <= nb;t++) {
					int d = -1;
					while (d < 0) {
						cout << "distance entre ville " << i << " et ville " << t << " ?" << endl;
						cin >> d;
					}
					p->gr->ajouterArc(p->gr->sommetS[i - 1], p->gr->sommetS[t - 1], d);
				}
			}
			int ville=0;
			while (ville <= 0 || ville > nb)
			{
				cout << "ville de depart ?";
				cin >> ville;
			}
			p->gr->afficher();
			p->setVilleDepart(ville);
			p->resolution(ville);
			cout << "la longeur du chemin plus court est " << p->resultat << endl;
		}
		default:
		{
			cout << "Commande invalide" << endl;
			break;
		}
		}
	}
}





