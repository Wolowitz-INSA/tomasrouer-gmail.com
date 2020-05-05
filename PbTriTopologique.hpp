#ifndef PBTRITOPOLOGIQUE_H_
#define PBTRITOPOLOGIQUE_H_

/*!
 * \file PbTriTopologique.hpp
 * \brief un probleme de tri-topologique
 * \author GroupeB7
 * \version 0.1
 */
#include "GrapheOriente.hpp"

    /*! \class PbTriTopologique
     * \brief classe representant un probleme a pour but de 
     * trier une liste a partir des relations
     */
    class PbTriTopologique
    {
    public:
        GrapheOriente *gr; /*!< Ensemble de taches et de relations, l'entree du probleme*/
    private:
        std::vector<int> candidat; /*!< Ensemble des candidats n'ayant pas de tache antecedante*/
        std::vector<Sommet> resultat; /*!< La sortie (liste triee) du probleme*/


    public:
        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe PbTriTopologique
         *
         */
        PbTriTopologique();



    public:
        /*!
         *  \brief Resolution du probleme
         *
         *  Afficher un message d'erreur si le problem n'est
         *  pas resouluble. Sinon afficher un graphe orientee
         *  pour chaque etape de resolution
         *
         */
       void resolution();
    };

#endif