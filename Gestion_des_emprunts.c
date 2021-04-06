#include "myfiles.h"


//------------------------------------------------emprunter_livre----------------------------------------------------------------------

void emprunter_livre(){
    livre liv;
    adherent adh;
    int c=0,n;
	FILE *f,*a,*fich,*F;
	//ouvrir les fichiers livre et adherent
	f=fopen("livres.txt","r");
	a=fopen("adherent.txt","r");
	 if (f==NULL || a==NULL)            // Test d'ouverture du fichier
    {
        printf("Erreur d'ouverture du fichier");
        return EXIT_SUCCESS;
    }
    char titre[20];
    printf("entrer le titre du livre que vous voulez emprunter :\n");
    scanf("%s",&titre);//lire le titre du livre à rendre
    do{ //chercher le titre dans le fichier livres
        fscanf(f,"%d #%s #%s #%s #%s #%d \n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
		if (!strcmp(liv.titre_liv,titre)&&liv.emprunteur_liv==-1){
			printf("ce livre est disponible \n ");

            //remplir dans le fichier temporaire
            printf(" numero: %d  titre: %s  categorie : %s  nom d'auteur : %s %s  nombre d'emprunts : %d	\n  ", liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.prenom_aut,liv.aut.nom_aut,liv.emprunteur_liv);
			c++;
			break ; }

       }while(!feof(f));//arreter une fois arriver à la fin du fichier
    if(c==0){ printf("ce livre n'est pas disponible !!");return ; }
     printf("entrer numero d'adherent");
    scanf("%d",&n);
    if( recherche_adh(n)==true){ //continuer que losque l'adherent exixte
       fich=fopen("tempAdherent.txt","a");//utiliser un fichier temporaire
        do{
            fflush(stdin);
           fscanf(a,"%d #%s #%s #%s #%s #%d\n",&(adh.num_adh),adh.nom_adh,adh.prenom_adh,adh.adress_adh,adh.email_adh,&(adh.nbre_emprunts_adh));
           if(n==adh.num_adh) {
                 adh.nbre_emprunts_adh++;//decrementer le nombre de livres empruntés
                 }
                 //
           fprintf(fich,"%d #%s #%s #%s #%s #%d\n",adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,adh.nbre_emprunts_adh);
        }while(!feof(a));//arreter une fois arriver à la fin du fichier
        fclose(a);
        fclose(fich);
        remove("adherent.txt");
        rename("tempAdherent.txt","adherent.txt");}

    F=fopen("templivres.txt","a");
    rewind(f);
        do{
           fflush(stdin);
           fscanf(f,"%d #%s #%s #%s #%s #%d\n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
           if (!strcmp(liv.titre_liv,titre)){
                liv.emprunteur_liv=n;}//numero d'mprunteur = -1 pour les livres non empruntés
           fprintf(F,"%d #%s #%s #%s #%s #%d\n",liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,liv.emprunteur_liv);

        }while(!feof(f));//arreter une fois arriver à la fin du fichier
        //fermer les fichiers
        fclose(F);
        fclose(f);
        remove("livres.txt");
        rename("templivres.txt","livres.txt");





    }



// -------------------------------------------------liste_livres----------------------------------------------------------------------
void liste_livres()
{
     printf("Affichage de la liste des livres empruntes :\n");
     livre liv;
     adherent adh;
     FILE *f,*a;
	 f=fopen("livres.txt","r");
	 a=fopen("adherent.txt","r");
	 if(f==NULL || a==NULL)//tester si le fichier est vide
        {
        printf("Impossible d'ouvrir le fichier \n");
        return 0;
        }
	  while(1){
        fflush(stdin)  ;
        //lire dans le fichier livre
        fscanf(f,"%d #%s #%s #%s #%s #%d \n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
        if(liv.emprunteur_liv!=-1){//-1 est le numéro d'emprunteur pour les livres libres (non empruntés)
         printf(" numero: %d  titre: %s  categorie : %s  nom d'auteur : %s %s  nombre d'emprunts : %d	\n  ", liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.prenom_aut,liv.aut.nom_aut,liv.emprunteur_liv);
         rewind(a);//remettre le cursseur au debut du fichier
         while (1){
            fflush(stdin);
            fscanf(a,"%d #%s #%s #%s #%s #%d\n",&(adh.num_adh),adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,&(adh.nbre_emprunts_adh));
            if(liv.emprunteur_liv==adh.num_adh){//trouver l'emprunteur du livre
             printf("emprinteur :numero : %d nom : %s %s email :  %s adresse :  %s nombre de livres emprintes : %d\n\n",adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,adh.nbre_emprunts_adh);
             break;}
             if(feof(a)) break; //sortir lorsqu'on arrive à la fin du fichier adherent
             }}
        if(feof(f)) break;//sortir lorsqu'on arrive à la fin du fichier adherent

	  }}















//-------------------------------------afficher_liste_emp-------------------------------------------------------------------------------

void afficher_liste_emp()
{
    printf("Affichage de la liste des adherents emprunteurs de livre :\n");
    adherent adh;
	FILE *f;
	f=fopen("adherent.txt","r");
	 if (f==NULL)            // Test d'ouverture du fichier
    {
        printf("Erreur d'ouverture du fichier");
        return EXIT_SUCCESS;
    }
    while (1){
            //lire dans le fichier adhrent
       fflush(stdin);
        fscanf(f,"%d #%s #%s #%s #%s #%d\n",&(adh.num_adh),adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,&(adh.nbre_emprunts_adh));
        if(adh.nbre_emprunts_adh!=0)  //verifier si l'adherent a emprunté au moins un livre
        //afficher l'derent s'il est emprunteur
        printf("numero : %d nom : %s %s email :  %s adresse :  %s nombre de livres emprintes : %d\n",adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,adh.nbre_emprunts_adh);
        if(feof(f)) break;//sortir lorsqu'on ariive à la fin du fichier
}

}












//-------------------------------------rendre_livre--------------------------------------------------------------------------------------


void Rendre_livre(){
    livre liv;
    adherent adh;
    int c=0,n,x;
	FILE *f,*a,*fich,*F;
	//ouvrir les fichiers livre et adherent
	f=fopen("livres.txt","r");
	a=fopen("adherent.txt","r");
	if (f==NULL || a==NULL)            // Test d'ouverture du fichier
    {
        printf("Erreur d'ouverture du fichier");
        return EXIT_SUCCESS;
    }
    char titre[20];
    printf("entrer le titre du livre que vous voulez render :\n");
    scanf("%s",&titre);//lire le titre du livre à rendre
    do{ //chercher le titre dans le fichier livres
        fscanf(f,"%d #%s #%s #%s #%s #%d \n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
		if (!strcmp(liv.titre_liv,titre)){//comparer le titre avec tous les titres existants
			printf("ce livre exite \n ");
			x=liv.num_liv;
			//afficher les informations du livre
            printf(" numero: %d  titre: %s  categorie : %s  nom d'auteur : %s %s  nombre d'emprunts : %d	\n  ", liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.prenom_aut,liv.aut.nom_aut,liv.emprunteur_liv);
			c++;//incrementer le conteur lorsqu'on trouve le livre recherché
			break ; }

       }while(!feof(f));//arreter une fois arriver à la fin du fichier
    if(c==0){ printf("introuvable !!");return ; }
     printf("entrer numero d'adherent");
    scanf("%d",&n);
    if( recherche_adh(n)==true){ //continuer que losque l'adherent exixte
       fich=fopen("tempAdherent.txt","a");//utiliser un fichier temporaire
        do{
            fflush(stdin);
           fscanf(a,"%d #%s #%s #%s #%s #%d\n",&(adh.num_adh),adh.nom_adh,adh.prenom_adh,adh.adress_adh,adh.email_adh,&(adh.nbre_emprunts_adh));
           if(n==adh.num_adh) {
                 adh.nbre_emprunts_adh--;//decrementer le nombre de livres empruntés
                 }
                 //
           fprintf(fich,"%d #%s #%s #%s #%s #%d\n",adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,adh.nbre_emprunts_adh);
        }while(!feof(a));//arreter une fois arriver à la fin du fichier
        fclose(a);
        fclose(fich);
        remove("adherent.txt");
        rename("tempAdherent.txt","adherent.txt");}

    F=fopen("templivres.txt","a");
    rewind(f);
        do{
           fflush(stdin);
           fscanf(f,"%d #%s #%s #%s #%s #%d\n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
           if (x==liv.num_liv){
                liv.emprunteur_liv=-1;}//numero d'mprunteur = -1 pour les livres non empruntés
           fprintf(F,"%d #%s #%s #%s #%s #%d\n",liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,liv.emprunteur_liv);

        }while(!feof(f));//arreter une fois arriver à la fin du fichier
        //fermer les fichiers
        fclose(F);
        fclose(f);
        remove("livres.txt");
        rename("templivres.txt","livres.txt");


    }





// -----------------menu_emprunts----------------------------------------------------------------------------------------------------
void menu_emprunts(){
    int choixMenu;
    SetColor(35);//Function call to change the text color
     printf("\n\t\t\t\t-----------------------------------------\n");
     printf("\t\t\t\t1. Emprunter un livre!\n");
     printf("\t\t\t\t2. Afficher liste des livres empruntes!\n");
     printf("\t\t\t\t3. Afficher la liste des adherents emprunteurs de livre\n");
     printf("\t\t\t\t4. Rendre un livre!\n");
     printf("\t\t\t\t5.retour au menu principal\n");
     printf("\t\t\t\t6-affichage (livres)\n");
     printf("\t\t\t\t7-affichage(adherents)\n");
     printf("\n\t\t\t\t-----------------------------------------\n");
     printf("\nVotre choix?\n\n");
     scanf("%d",&choixMenu);
     printf("\n\n");

     switch(choixMenu)
    {
                     case 1:
                          emprunter_livre();

                          break;
                     case 2:
                          liste_livres();
                          menu_principal();
                          break;
                     case 3:
                          afficher_liste_emp();
                          menu_principal();
                          break;
                     case 4:
                          Rendre_livre();
                          menu_principal();
                          break;
                    case 5:
                          system("cls");
                          menu_principal();
                          break;
                     case 6:
                          affichage_liv();
                          menu_principal();
                          break;
                     case 7:
                          affichage_adh();
                          menu_principal();
                          break;
                     default:
                         printf("Vous ne ferez rien du tout!\n");
                         menu_principal();
                         break;
    }
}

