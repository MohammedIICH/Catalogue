/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER ET ERABHAOUI
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

#include <cstring>

//-------------------------------------------------------- Inclusion système
using namespace std;
#include <iostream>

//------------------------------------------------------ Inclusion personnelle
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher(void) const
// Algorithme :
//
{
    if (mTailleCourante == 0 || mListe == nullptr)
    {
        cout << "Le catalogue " << mNom << " est vide" << endl;
        return;
    }

    cout << "Contenu du catalogue de trajets " << mNom << " (simples ou composes) : " << endl;

    for (int i = 0; i < mTailleCourante; ++i)
    {
        mListe[i]->Afficher();
    }

    cout << endl;
} // Fin de la méthode Afficher

void Catalogue::Redimensionner()
// Algorithme :
//
{
#ifdef MAP
    cout << "Redimensionnement du catalogue" << endl;
#endif
    mTailleListe += 10;
    Trajet **nvmListe = new Trajet *[mTailleListe];
    for (int i = 0; i < mTailleCourante; i++)
    {
        nvmListe[i] = mListe[i];
    }
    delete[] mListe;
    mListe = nvmListe;
} // Fin de la méthode Redimensionner

void Catalogue::AjouterTrajet(Trajet *trajet)
// Algorithme :
//
{
    if (mTailleCourante >= mTailleListe)
    {
        Redimensionner();
    }
    mListe[mTailleCourante++] = trajet;
} // Fin de la méthode AjouterTrajet

void Catalogue::RechercheAvancee(const char *depart, const char *arrivee) const
{
    const int MAX_VILLES = 2 * (mTailleCourante + 1);
    const char **villes = new const char *[MAX_VILLES]();
    for (int i = 0; i<MAX_VILLES; ++i) villes[i] = nullptr;
    int nbVilles = 0;

    bool *visited = new bool[mTailleListe]();
    Trajet **trajetsParcourus = new Trajet *[MAX_VILLES](); // Tableau pour stocker les trajets empruntés
    for (int i = 0; i<MAX_VILLES; ++i) trajetsParcourus[i] = nullptr;
    int nbTrajets = 0;

    cout << "Recherche des trajets possibles de " << depart << " a " << arrivee << " :" << endl;
    bool trajetTrouve = false; //booleen utile pour afficher si aucun trajet n'est trouve à la fin
    dfs(depart, depart, arrivee, visited, villes, nbVilles, trajetsParcourus, nbTrajets, trajetTrouve);

    if (!trajetTrouve)
    {
        cout << "Aucun trajet trouve de " << depart << " a " << arrivee << "." << endl;
    }

    delete[] villes;
    delete[] trajetsParcourus;
    delete[] visited;
}


void Catalogue::RechercheSimple(const char *depart, const char *arrivee) const
// Algorithme :
//
{
    bool found = false;

    for (int i = 0; i < mTailleCourante; i++)
    {
        if (strcmp(mListe[i]->GetDepart(), depart) == 0 && strcmp(mListe[i]->GetArrivee(), arrivee) == 0)
        {
            found = true;
            if (found) cout << "Trajet trouve : " << endl;
            mListe[i]->Afficher();
        }
    }

    if (!found)
    {
        cout << "Aucun trajet trouve de " << depart << " a " << arrivee << "." << endl;
    }
} // Fin de la méthode RechercheSimple

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue(const char *nom, Trajet **Liste, int taille) : mTailleListe(taille)
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

    mNom = new char[strlen(nom) + 1];
    strcpy(mNom, nom);
    mListe = new Trajet *[mTailleListe];

    if (Liste != nullptr)
    {
        for (int i = 0; i < taille; i++)
        {
            mListe[i] = Liste[i];
        }
    }
} // Fin du constructeur Catalogue

Catalogue::Catalogue(const char *nom)
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    mNom = new char[strlen(nom) + 1];
    strcpy(mNom, nom);
    mTailleListe = 10;
    mTailleCourante = 0;
    mListe = new Trajet *[10];
} // Fin du constructeur Catalogue

Catalogue::~Catalogue()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    delete[] mNom;
    int i;
    for (i = 0; i<mTailleCourante; i++)
    {
        delete mListe[i];
    }
    delete[] mListe; // Libérer la mémoire allouée pour la liste de trajets
} // Fin du destructeur Catalogue

//-------------------------------------------------- Méthodes protégées
bool Catalogue::villeDejaRencontree(const char *ville, const char *villes[], int nbVilles) const
// Algorithme : Vérifier si une ville est déjà présente dans la liste des villes explorées
// Parcours du tableau des villes et vérifie si la ville actuelle existe déjà.
{
    for (int i = 0; i < nbVilles; ++i)
    {
        if (strcmp(villes[i], ville) == 0)
        {
            return true;
        }
    }
    return false;
} // Fin de la méthode villeDejaRencontree

void Catalogue::ajouterVille(const char *ville, const char *villes[], int &nbVilles) const
// Algorithme : Ajouter une ville à la liste des villes explorées
// Si la ville n'a pas encore été rencontrée et que le nombre de villes est inférieur à 100, on l'ajoute à la liste.
{
    if (!villeDejaRencontree(ville, villes, nbVilles) && nbVilles < 100)
    {
        villes[nbVilles++] = ville;
    }
} // Fin de la méthode ajouterVille

void Catalogue::dfs(const char *current, const char *depart, const char *arrivee, 
                    bool *visited, const char *villes[], int &nbVilles, 
                    Trajet *trajetsParcourus[], int &nbTrajets, bool &trajetTrouve) const
{
    ajouterVille(current, villes, nbVilles);

    if (strcmp(current, arrivee) == 0)
    {
        // Afficher les trajets parcourus jusqu'ici
        
        if (!trajetTrouve) cout << "Chemin trouve :" << endl;
        trajetTrouve = true;
        for (int i = 0; i < nbTrajets; ++i)
        {
            cout << trajetsParcourus[i]->GetNom();
            if ((i<nbTrajets-1)&&(strcmp(trajetsParcourus[i]->GetArrivee(),trajetsParcourus[i+1]->GetDepart())==0))
            {
                cout << " + ";
            }

        }
        cout << endl;
        return;
    }

    for (int i = 0; i < mTailleCourante; ++i)
    {
        if (!visited[i] && strcmp(mListe[i]->GetDepart(), current) == 0)
        {
            visited[i] = true;
            trajetsParcourus[nbTrajets++] = mListe[i]; // Ajouter le trajet courant au tableau

            dfs(mListe[i]->GetArrivee(), depart, arrivee, visited, villes, nbVilles, trajetsParcourus, nbTrajets, trajetTrouve);

            visited[i] = false;
            --nbTrajets; // Revenir en arrière, retirer le trajet du tableau
        }
    }
} // Fin de la méthode dfs

