/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER et ELRABHAOUI
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(Trajet_H)
#define Trajet_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher(void) const = 0;
    // Mode d'emploi :
    //Cette méthode est virtuelle pure, elle doit être redefinie dans les classes filles.
    // Contrat :
    //
    
    const char* GetDepart(void) const; 
    // Mode d'emploi :
    //Cette methode retourne un pointeur constant sur la ville de départ
    // Contrat :
    //
    
    const char* GetArrivee(void) const; 
    // Mode d'emploi :
    //Cette methode retourne un pointeur constant sur la ville d'arrivée
    // Contrat :
    //

    const char* GetNom(void) const; 
    // Mode d'emploi :
    //Cette méthode retour un pointeur constant sur le nom du trajet
    // Contrat :
    //
    
    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    
    Trajet(const char *Depart, const char *Arrivee, const char *Nom);
    // Mode d'emploi :
    //Cette méthode construit un trajet à partir du Depart, de l'arrivée et de son nom
    // Contrat :
    //

    virtual ~Trajet();
    // Mode d'emploi :
    //Cette méthode détruit un trajet, elle doit être virtuelle.
    // Contrat :
    //

protected:
    //----------------------------------------------------- Méthodes protégées
    //----------------------------------------------------- Attributs protégés
    char *mDepart;
    char *mArrivee;
    char *mNom;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H
