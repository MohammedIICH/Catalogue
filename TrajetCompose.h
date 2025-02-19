/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER et ELRABHAOUI
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if !defined(TrajetCompose_H)
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Afficher(void) const;
    // Mode d'emploi :
    //Cette méthode affiche un trajet Composé
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    TrajetCompose(const char *nom, TrajetSimple **ListeTrajetsSimples, int taille);
    // Mode d'emploi :
    //Cette méthode construit un trajet composé à partir de son nom, d'une Liste de Trajets Simples et de sa taille
    // Contrat :
    //

    TrajetCompose(const TrajetCompose &unAutre);
    // Mode d'emploi :
    //Cette méthode Copie le trajet composé fourni par reference
    // Contrat :
    //

    virtual ~TrajetCompose();
    // Mode d'emploi :
    //Cette méthode détruit des trajets composés
    // Contrat :
    //

protected:
    //----------------------------------------------------- Méthodes protégées
    //----------------------------------------------------- Attributs protégés
    TrajetSimple **mListeTrajetsSimples;
    int mTaille;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
