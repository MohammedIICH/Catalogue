/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER et ELRABHAOUI
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Afficher(void) const;
    // Mode d'emploi :
    //Cette méthode affiche un Trajet Simple
    // Contrat :
    //

    const char *get_mMt(void) const;
    // Mode d'emploi :
    //Cette méthode retourne un pointeur constant sur le Moyen de transport
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const char *depart, const char *arrivee, const char *nom, const char *mt);
    // Mode d'emploi :
    //Cette méthode construit un trajet simple à partir de son départ, arrivée, nom et moyen de transport
    // Contrat :
    //

    TrajetSimple(const TrajetSimple &autre);
    // Mode d'emploi :
    //Cette méthode copie un trajet simple à partir d'un trajet simple fourni par réference.
    // Contrat :
    //

    virtual ~TrajetSimple();
    // Mode d'emploi :
    //Cette méthode détruit un trajet simple
    // Contrat :
    //

protected:
    //----------------------------------------------------- Méthodes protégées
    //----------------------------------------------------- Attributs protégés
    char *mMt;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
