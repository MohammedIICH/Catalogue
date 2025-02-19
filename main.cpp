/*************************************************************************
                           Menu  -  main
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par IICH, LEMSEFFER ET ERABHAOUI
    e-mail               : $EMAIL$
*************************************************************************/

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

using namespace std;

void intToStr(int, char *); //Fonction pour transformer un entier en char* : ex : 132->"132"

int main()
{
    static int numTS = 0;
    static int numTC = 0;
    Catalogue catalogue("C1");

    for (;;)
    {
        cout << "Menu :" << endl;
        cout << "1. Affichage du catalogue" << endl;
        cout << "2. Ajouter trajet simple" << endl;
        cout << "3. Ajouter trajet compose" << endl;
        cout << "4. Recherche simple" << endl;
        cout << "5. Recherche avancee" << endl;
        cout << "6. Quitter" << endl;

        int n;
        cin >> n;

        switch (n)
        {
        case 1:
            catalogue.Afficher();
            break;

        case 2:
        {
            cout << "Depart :" << endl;
            char depart[100];
            cin >> depart;

            cout << "Arrivee :" << endl;
            char arrivee[100];
            cin >> arrivee;

            if (strcmp(depart,arrivee) == 0)
            {
                cerr << "Le depart et l'arrivee doivent etre differents" << endl;
                break;
            }

            cout << "Nom du moyen de transport : ";
            char MT[100];
            cin >> MT;

            //Nommage automatique des Trajets
            char nom[23] = "TS";
            char nombreStr[20];
            intToStr(++numTS, nombreStr);
            strcat(nom, nombreStr);

            Trajet * trajet = new TrajetSimple(depart, arrivee, nom, MT);
            catalogue.AjouterTrajet(trajet);
            break;
        }

        case 3:
{
    cout << "Saisie d'un trajet composé" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "NOMBRE de trajets simples : ";
    int NbTS;
    cin >> NbTS;

    if (NbTS <= 1)
    {
        cerr << "Le nombre de trajets ne peut pas être 1 ou moins." << endl;
        break;
    }

    cout << "-------------------------------------------------------" << endl;
    cout << "Donnez dans l'ordre les " << NbTS << " trajets simples" << endl;

    TrajetSimple** ListeTrajetsSimples = new TrajetSimple*[NbTS];
    bool erreur = false;
    int i;

    for (i = 0; i<NbTS; ++i)
    {
        cout << "-------------------------------------------------------" << endl;
        cout << "Entrez les donnees du trajet " << i+1 << endl;
                
        cout << "Depart :" << endl;
        char depart[100];
        cin >> depart;

        if ((i>=1)&&(strcmp(ListeTrajetsSimples[i-1]->GetArrivee(),depart)!=0)) erreur = true;

        cout << "Arrivee :" << endl;
        char arrivee[100];
        cin >> arrivee;

        cout << "Nom du moyen de transport : ";
        char MT[100];
        cin >> MT;

        //Nommage automatique des Trajets
        char nom[23] = "TS";
        char nombreStr[20];
        intToStr(++numTS, nombreStr);
        strcat(nom, nombreStr);            

        ListeTrajetsSimples[i] = new TrajetSimple(depart, arrivee, nom, MT);
    }

    if (strcmp(ListeTrajetsSimples[NbTS-1]->GetArrivee(),ListeTrajetsSimples[0]->GetDepart())==0) erreur = true;
    if (!erreur)
    {
        //Nommage automatique des Trajets
        char nom[23] = "TC";
        char nombreStr[20];
        intToStr(++numTC, nombreStr);
        strcat(nom, nombreStr);

        Trajet * TC = new TrajetCompose(nom, ListeTrajetsSimples, NbTS);
        catalogue.AjouterTrajet(TC);
    }

    if (erreur) cerr << "Le trajet compose est invalide (discontinu ou boucle)" << endl;

    for (i = 0; i<NbTS; i++)
    {
        delete ListeTrajetsSimples[i];
    }
    delete [] ListeTrajetsSimples;
    break;
}


        case 4:
        {
            cout << "Depart :" << endl;
            char depart[100];
            cin >> depart;

            cout << "Arrivee :" << endl;
            char arrivee[100];
            cin >> arrivee;

            catalogue.RechercheSimple(depart, arrivee);

            break;
        }

        case 5:
        {
            cout << "Depart :" << endl;
            char depart[100];
            cin >> depart;

            cout << "Arrivee :" << endl;
            char arrivee[100];
            cin >> arrivee;

            catalogue.RechercheAvancee(depart, arrivee);

            break;
        }

        case 6:
            cout << "Au revoir :)" << endl;
            return 0;

        default:
            cout << "Choix invalide !" << endl;
            break;
        }
    }
    return 0;
}

//Fonction qui convertit int en char* pour nommer automatiquement les trajets dans le menu (on aurait pu utiliser sprintf)
void intToStr(int num, char *str) {
// Algorithme : Suite de divisions euclidiennes pour decomposer en puissances de 10
//
    int i = 0, j;
    char tempChar;

    if (num == 0) {
        str[i++] = '0';
    } else {
        while (num > 0) {
            str[i++] = (num % 10) + '0';
            num /= 10;
        }
    }
    str[i] = '\0'; 

    //Inversion du chiffre obtenu
    for (j = 0; j < i / 2; j++) {
        tempChar = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = tempChar;
    }
}