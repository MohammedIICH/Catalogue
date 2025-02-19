/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER et ELRABHAOUI
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include <cstring>
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher(void) const
// Algorithme :
//
{
    cout << mNom << " = de ";
    for (int i = 0; i < mTaille; ++i)
    {
        cout << mListeTrajetsSimples[i]->GetDepart() << " a " << mListeTrajetsSimples[i]->GetArrivee() << " en " << mListeTrajetsSimples[i]->get_mMt();
        if (i != mTaille - 1)
            cout << " - ";
    }

    cout << endl;

} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(const char *nom, TrajetSimple **ListeTrajetsSimples, int taille) : Trajet(ListeTrajetsSimples[0]->GetDepart(), ListeTrajetsSimples[taille-1]->GetArrivee(), nom), mTaille(taille)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

    if (taille <= 1)
    {
        throw invalid_argument("On a pas d'etape intermediare, ce trajet est simple");
    }
    if (ListeTrajetsSimples == nullptr)
    {
        throw invalid_argument("Liste des trajets simples ne peut pas être nulle.");
    }

    mListeTrajetsSimples = new TrajetSimple *[mTaille];
    for (int i = 0; i < mTaille; ++i)
    {
        if (ListeTrajetsSimples[i] == nullptr)
        {
            throw invalid_argument("Un trajet simple dans la liste ne peut pas être nul.");
        }

        if ((i<mTaille-1)&&(strcmp(ListeTrajetsSimples[i]->GetArrivee(),ListeTrajetsSimples[i+1]->GetDepart())!=0))
        {
            throw invalid_argument("Votre trajet compose est discontinu");
        }

        mListeTrajetsSimples[i] = new TrajetSimple(*ListeTrajetsSimples[i]);
    }

} //----- Fin de TrajetCompose (constructeur)

TrajetCompose::TrajetCompose(const TrajetCompose &unAutre): Trajet(unAutre.mDepart, unAutre.mArrivee, unAutre.mNom), mTaille(unAutre.mTaille)
// Algorithme : Copie profonde 
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif

    mListeTrajetsSimples = new TrajetSimple *[mTaille];


    for (int i = 0; i < mTaille; ++i)
    {
        mListeTrajetsSimples[i] = new TrajetSimple(*unAutre.mListeTrajetsSimples[i]);
    }
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    int i;
    for (i = 0; i < mTaille; i++)
    {
        delete mListeTrajetsSimples[i];
    }
    delete[] mListeTrajetsSimples;
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées