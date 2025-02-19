/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER et ELRABHAOUI
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include <cstring>
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher(void) const
// Algorithme :
//
{
    cout << mNom << " = de ";
    cout << mDepart << " a " << mArrivee << " en " << mMt <<endl;
} //----- Fin de Méthode


const char *TrajetSimple::get_mMt() const
{
    return mMt;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char *depart, const char *arrivee, const char *nom, const char *mt) : Trajet(depart, arrivee, nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    int taille = strlen(mt);
    mMt = new char[taille + 1];
    strcpy(mMt, mt);
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple(const TrajetSimple &autre) : Trajet(autre.mDepart, autre.mArrivee, autre.mNom)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif

    mMt = new char[strlen(autre.mMt) + 1];
    strcpy(mMt, autre.mMt);
}

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete[] mMt;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
