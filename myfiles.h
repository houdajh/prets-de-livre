#ifndef _FUNCTION
#define _FUNCTION
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>




typedef struct _adherent {
	int num_adh ;
	char nom_adh[20];
	char prenom_adh[30];
	char email_adh[100];
	char adress_adh[100];
	int  nbre_emprunts_adh;

}adherent;
typedef struct auteur_liv{
	char nom_aut[50];
	char prenom_aut[50];
}auteur;

auteur  aut;
typedef struct _livre {
	int num_liv ;
	char titre_liv[50];
	char categ_liv[50];
    auteur  aut;
	int emprunteur_liv;  // emprunteur_liv=num_adh
}livre;


// fonctions auxiliaires
bool recherche_adh(int numrech);
bool recherche_liv(int numrech);

// ajout
void ajout_adh();
void ajout_liv();
//suppression
void supp_adh();
void supp_liv();
//recherche
void rech_livre();
void rech_adherent();
//modification
void modifierAdherent();
void modifierlivre();

void ordonner_Liv();
//gestion des emprunts
void liste_livres();
void afficher_liste_emp();
void Rendre_livre();
void emprunter_livre();

//menu
void menu_principal();
void affichageMenu_adh();
void affichageMenu_liv();

//affichage
void affichage_adh();
void affichage_liv();


//style

void menu_principal();
void SetColor(int ForgC);
void merci();
void livre_sty();
void bienvenue();






#endif
