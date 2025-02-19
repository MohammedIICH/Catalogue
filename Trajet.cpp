/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER et ELRABHAOUI
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char* Trajet::GetDepart() const 
// Algorithme :
//
{ 
    return mDepart; 
} //----- Fin

const char* Trajet::GetArrivee() const 
{ 
    return mArrivee; 
} //----- Fin

const char* Trajet::GetNom() const 
{ 
    return mNom; 
} //----- Fin

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet(const char *Depart, const char *Arrivee, const char *Nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif

    mNom = new char[strlen(Nom) + 1];
    strcpy(mNom, Nom);

    if (strcmp(Depart, Arrivee) == 0)
    {
        throw invalid_argument("Le Depart et l'arrivee doivent etre differents");
    }

    mDepart = new char[strlen(Depart) + 1];
    strcpy(mDepart, Depart);

    mArrivee = new char[strlen(Arrivee) + 1];
    strcpy(mArrivee, Arrivee);

} //----- Fin de Trajet

Trajet::~Trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif

    delete[] mNom;
    delete[] mDepart;
    delete[] mArrivee;

} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
