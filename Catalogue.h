/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER ET ERABHAOUI
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----
#if !defined(Catalogue_H)
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// La classe Catalogue gère une collection de trajets et permet d'effectuer
// des recherches simples ou avancées, d'ajouter de nouveaux trajets
// et d'afficher la liste des trajets disponibles dans le catalogue.
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques
    void Afficher(void) const;
    // Mode d'emploi :
    // Cette méthode parcourt la liste des trajets et les affiche un par un.
    //
    // Contrat :
    //
    
    void Redimensionner(void);
    // Mode d'emploi :
    // Cette méthode redimensionne la liste des trajets de catalogue si notre catalogue est plein.
    //
    // Contrat :
    //
    
    void RechercheAvancee(const char *depart, const char *arrivee) const;
    // Mode d'emploi :
    // Cette méthode permet d'effectuer une recherche avancée avec le principe de transitivité multiple.
    //
    // Contrat :
    //

    void RechercheSimple(const char *depart, const char *arrivee) const;
    // Mode d'emploi :
    // Cette méthode effectue une recherche simple en vérifiant les correspondances exactes entre le départ et l'arrivée.
    //
    // Contrat :
    //

    void AjouterTrajet(Trajet * trajet);
    // Mode d'emploi :
    // Cette méthode ajoute un objet Trajet à la liste des trajets du catalogue.
    //
    // Contrat :
    // Le trajet ne doit pas être un pointeur nul.

    //-------------------------------------------- Constructeurs - destructeur
    Catalogue(const char *nom);
    // Mode d'emploi :
    // Crée un objet Catalogue avec un nom spécifié.
    // Initialise la liste des trajets comme vide et la taille à 0.
    //
    // Contrat :
    // Le nom ne doit pas être un pointeur nul.

    Catalogue(const char *nom, Trajet **Liste, int taille);
    // Mode d'emploi :
    // Constructeur de copie de la classe Catalogue.
    //
    // Contrat :
    // Le nom ne doit pas être un pointeur nul.

    virtual ~Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

protected:
    //----------------------------------------------------- Méthodes protégées
    bool villeDejaRencontree(const char *ville, const char *villes[], int nbVilles) const;
    void ajouterVille(const char *ville, const char *villes[], int &nbVilles) const;
    void dfs(const char *current, const char *depart, const char *arrivee, 
                    bool *visited, const char *villes[], int &nbVilles, 
                    Trajet *trajetsParcourus[], int &nbTrajets, bool &trajetTrouve) const;
    //----------------------------------------------------- Attributs protégés
    char *mNom;       // Nom du catalogue
    Trajet **mListe;  // Liste des trajets dans le catalogue
    int mTailleListe; // Taille (en memoire) de la liste des trajets
    int mTailleCourante; //Tialle effective de la liste des trajets
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
