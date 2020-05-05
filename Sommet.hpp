#ifndef SOMMET_H_
#define SOMMET_H_

/*!
 * \file Sommet.hpp
 * \brief sommet de graphe
 * \author GroupeB7
 * \version 0.1
 */
#include <string>


    /*! \class Sommet
     * \brief classe representant le sommet
     */
class Sommet
{
private:
    std::string presentation; /*!< Presentation du sommet pour l'affichage*/
    int valeur; /*!< poids du sommet */
    bool visite;/*!< si le sommet est visite */


public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Sommet
     *
     *  \param nom : presentation initiale du sommet
     */

    Sommet(std::string nom);

    Sommet();



public:
    /*!
     *  \brief Lecture du poids
     *
     *  \return valeur du poids
     */
    int getValeur();

    /*!
     *  \brief Modification du poids
     *
     *  \param np : nouveau poids
     */
    void setValeur(int np);

    /*!
     *  \brief Lecture de la presentation
     *
     *  \return la chiane de charactere pour la presentation
     */
    std::string getPresentation();

    /*!
     *  \brief Modification de la presentation
     *
     *  \param nom : nouvelle presentation
     */
    void setPresentation(std::string nom);

    bool getVisite();

    void setVisite(bool v);
    /*!
     *  \brief Redefinir l'operateur = pour la classe Sommet
     *
     *  On fera une photocopie de s
     */
    void operator= (const Sommet & s);
    /*!
     *  \brief Redefinir l'operateur == pour la classe Sommet
     *
     *  On compare notre sommet avec le sommet s 
     */
    bool operator==(const Sommet& s);
    };

#endif