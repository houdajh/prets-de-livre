//---------------------------------------adherents-------------------------------------------------------------------------------------
#include "myfiles.h"


//fonction auxiliaire :il cherche si l'adherent existe au non
bool recherche_adh(int numrech){
	adherent adh;
	FILE *f=NULL;
	f=fopen("adherent.txt","r");  //c'est pas la peine d'ecrire un chemin physique car mon fichier et le projet sont dans le meme repertoire
	if(f==NULL)//tester si le fichier existe
        {
        printf("Impossible d'ouvrir le fichier \n");
        return 0;
        }
	do{
		fscanf(f,"%d #%s #%s #%s #%s #%d\n",&(adh.num_adh),adh.nom_adh,adh.prenom_adh,adh.adress_adh,adh.email_adh,&(adh.nbre_emprunts_adh));
		fflush(stdin); // pour liberer la memoire
		if (adh.num_adh==numrech){  //si on a trouvé l'adherent dans le fichier
			fclose(f);
			return true ; // c'est a dire on a trouvé l'adherent
		}
	}while (!feof(f)); // jusqu'a la fin du fichier
	fclose(f);
	return false; //on est  utilisé :#include<stdbool.h>

}

//----------------------------------------------------ajout_adh------------------------------------------------------------------------
void ajout_adh(){
	adherent adh; // adh variable de type adherent
	FILE *f=NULL;
	int num;
	f=fopen("adherent.txt","a"); // ouverture en mode d'ajout ,si le fichier n'existe pas il va le crer
	if(f==NULL) //tester si le fichier existe
        {
        printf("Impossible d'ouvrir le fichier \n");
        return 0;
        }
        do{
	printf("entrer le numero du nouveau adherent:\n");
	printf("le numero doit etre strictement positif\n");
	scanf("%d",&num);
	fflush(stdin);// liberer memoire
        }while(num<=0);

	while(recherche_adh(num)){ // si l'adherent existe deja ,il va demander un autre numero
		printf("cet adherent est deja exister\n");
		printf("entrer le numero de l'adherent \n");
		scanf("%d",&num);
	}
	// maintenant recuperer les informations
	adh.num_adh=num;
	printf("entrer le nom\n");
	gets(adh.nom_adh);
	fflush(stdin); // fflush(stdin) c'est pour eviter les problemes de memoire
	printf("entrer le prenom\n");
	gets(adh.prenom_adh);
	fflush(stdin);
	printf("entrer l'email\n");
	gets(adh.email_adh);
	fflush(stdin);
	printf("entrer l'adresse'\n");
	gets(adh.adress_adh);
	fflush(stdin);
	printf("entrer le nombre de livres empruntés\n");
	scanf("%d",&(adh.nbre_emprunts_adh));
	if(adh.nbre_emprunts_adh >3)  { // dans le cahier de charge Un adhérent peut emprunter max 3 livres
        printf("cet adherent a pris plus de 3 livres\n");
        menu_principal(); // sortir du programme
	}
	if(adh.nbre_emprunts_adh <0)  { // dans le cahier de charge Un adhérent peut emprunter max 3 livres
        printf("le numero doit etre positif\n");
        menu_principal(); // sortir du programme
	}
	fprintf(f,"%d #%s #%s #%s #%s #%d\n",adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,adh.nbre_emprunts_adh); // ecrire la ligne dans notre fichier

	fclose(f);// fermer le fichier
}

//---------------------------------------------modifierAdherent------------------------------------------------------------------------

void modifierAdherent(){
adherent adh; //adh:variable de type adherent
FILE*F=NULL,*fich=NULL;
int num,i;
char rep='n';
printf("\n entrer le numero de l adherent a modifier :\n");
scanf("%d",&num);
fflush(stdin);
if(recherche_adh(num)){// si l'adherent existe dans le fichier on va le modifier
    do{
    printf("\n voulez vous vraiment modifier o|n \n?");//les précautions
    scanf("%c",&rep);
    fflush(stdin);
    }while(!(rep=='o' || rep=='n' || rep=='N' || rep=='O' ));
    printf("%c",rep);
    if(rep=='o' || rep=='O'){
        F=fopen("adherent.txt","r"); // OUVRIR en mode lecture
        fich=fopen("tempAdherent.txt","a");// ouvrir en mode d'ajout (pour crer le fichier) c'est un fichier temporaire
        if(F==NULL || fich==NULL) //tester si le fichier existe
        {
        printf("Impossible d ouvrir le fichier \n");
        return 0;
        }
        do{
            // pour recuperer les donnes
           fscanf(F,"%d #%s #%s #%s #%s #%d\n",&(adh.num_adh),adh.nom_adh,adh.prenom_adh,adh.adress_adh,adh.email_adh,&(adh.nbre_emprunts_adh));
           if(num==adh.num_adh){// si on a trouver notre choix
            adh.num_adh=num;
            printf("\nentrer le nouveau nom:");
            gets(adh.nom_adh);
            fflush(stdin);//liberer la memoire
	        printf("entrer le prenom\n");
	        gets(adh.prenom_adh);
	        fflush(stdin);
	        printf("entrer l'email\n");
	        gets(adh.email_adh);
	        fflush(stdin);
	        printf("entrer l'adresse'\n");
	        gets(adh.adress_adh);
	        fflush(stdin);
	        do{
	        printf("entrer le nombre de livres empruntes max 3\n");
        	scanf("%d",&(adh.nbre_emprunts_adh));
	        fflush(stdin);
	        }while(adh.nbre_emprunts_adh>3 || adh.nbre_emprunts_adh<0);
           }
           // ajouter la ligne
           fprintf(fich,"%d #%s #%s #%s #%s #%d\n",adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,adh.nbre_emprunts_adh);// remlir le fichier temporaire par les nouveaux donnees
        }while(!feof(F)); // test the end of file
        fclose(F);//fermer les deux fechiers
        fclose(fich);
        remove("adherent.txt");// supprimer les anciennes informations
        rename("tempAdherent.txt","adherent.txt");// renommer le fichier qui contient les informationd desirees
        printf("\n modification effectuer avec success ");
    }
    else{
        printf("\la modification est annulée\n");// on a choisit 'n'
    }
}
else{
    printf("\ncet adherent n'existe pas\n");// recherche_adh return false
}
}


//------------------------------------------------supp_adh-----------------------------------------------------------------------------
void supp_adh(){
	adherent adh;// liv variable de type livre
	char rep;
	int numrech;
	printf("entrer le nombre de l'adherent a surpprimer:\n");// le nombre du adherent est unique
	scanf("%d",&numrech);
	fflush(stdin);
	if(recherche_adh(numrech)){// si le numero est vraiment existe dans le fichier des donnees
        do{
		printf("voulez vous vraiment supprimer o/n:\n");
		scanf("%c",&rep);
		fflush(stdin);
        }while(!(rep=='o' || rep=='n' || rep=='N' || rep=='O' ));// soit oui soit non
		if(rep=='o'|| rep =='O'){// si oui
			FILE *fich=NULL,*f=NULL;
			f=fopen("adherent.txt","r");
			fich=fopen("temps_adherent.txt","a");// c'est un fichier temporaire
			 if (f==NULL)            // Test d'ouverture du fichier
    {
        printf("Erreur d'ouverture du fichier");
        return EXIT_SUCCESS;
    }

			do{
                    //recuperer nos donnees
            fscanf(f,"%d #%s #%s #%s #%s #%d\n",&adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.adress_adh,adh.email_adh,&(adh.nbre_emprunts_adh));

			if(numrech!=adh.num_adh){// si la ligne contient le livre qu'on ne veut pas le supprimer, on va l'ajouter dans le fichier temporaire
                fprintf(fich,"%d #%s #%s #%s #%s #%d\n",adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.adress_adh,adh.email_adh,adh.nbre_emprunts_adh);

			}
			}while(!feof(f));// parcourir tous le fichier
			fclose(fich);// fermer les deux fichiers
			fclose(f);
			remove("adherent.txt");// supprimer l'ancien fichier
			rename("temps_adherent.txt","adherent.txt");// renommer le nouveau fichier
			printf("suppression effectuer avec success");
		}
		else{
			printf("la suppression est annulée \n");// l'utilisateur a choisit non
		}

	}
	else{
		printf("ce numero n'existe pas\n");// le numero n'existe pas parmi nos donnees
	}

}


//----------------------------------rech_adherent-------------------------------------------------------------------------------------
void rech_adherent(){

        char nom[20] ,prenom[20], choix[20];
        int c=0 ;
        adherent adh;// adh variable de type adherent
        FILE *f=NULL;
        f=fopen("adherent.txt","r");
         if (f==NULL)            // Test d'ouverture du fichier
    {
        printf("Erreur d'ouverture du fichier");
        return EXIT_SUCCESS;
    }
        printf("entrer le nom d'adherent : ");

        fflush(stdin);// liberer la memoire
        gets(nom);
        while (1){
                // recuperer nos informations
        fscanf(f,"%d #%s #%s #%s #%s #%d\n",&(adh.num_adh),adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,&(adh.nbre_emprunts_adh));
		if (!strcmp(adh.nom_adh,nom)){// si on a trouver le nom désiré
			c++;// le nombre des adherent qui ont le meme nom
        // affichage

			printf("%d- numero: %d  nom: %s  prenom: %s  email : %s  adresse : %s  nombre d'emprunts : %d	\n  ",c,adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,adh.nbre_emprunts_adh); }
        if(feof(f)) break;// pour eviter la boucle infini
       }
       if(c==0) printf("introuvable !!");// on a pas trouver un adherent avec ce nom
        if (c>1) {// si ce nom existe
            do{
            printf(" une recherche plus pricise oui/non ?  ");
            gets(choix);
            // soit oui soit non
            }while(!(!strcmp(choix,"oui") || !strcmp(choix,"OUI")  ||  !strcmp(choix,"Oui")  || !strcmp(choix,"non") || !strcmp(choix,"NON")  ||  !strcmp(choix,"Non")));
            if(!strcmp(choix,"oui") || !strcmp(choix,"OUI")  ||  !strcmp(choix,"Oui")){// si l'utilisateur a choisit oui
            printf("entrer le prenom");
            gets(prenom);
            fflush(stdin);
             rewind(f);// remettre le cursseur au debut du fichier
             while (1){// de meme recherche par prenom

        fflush(stdin);
        // recuperer nos informations
        fscanf(f,"%d #%s #%s #%s #%s #%d\n",&(adh.num_adh),adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,&(adh.nbre_emprunts_adh));
		if (!strcmp(adh.prenom_adh,prenom)){// si la ligne contient le prenom desiré on va afficher
			printf(" numero: %d  nom: %s  prenom: %s  email : %s  adresse : %s  nombre d'emprunts : %d	\n  ",adh.num_adh,adh.nom_adh,adh.prenom_adh,adh.email_adh,adh.adress_adh,adh.nbre_emprunts_adh);
            return ; // pour sortir
             }
        if(feof(f)) break;//pour sortir de la boucle while(1)
       }}
     else printf("/n"); // c'est pas la peine d'afficher un message  ;
       }

        fclose(f);// fermer le fichier

            }




 //----------------------------------------------affichage----------------------------------------------------------------------------

 void affichage_adh(){
    FILE *f=NULL;
    char chaine[1000]="";
    f=fopen("adherent.txt","r");
    if(f==NULL) //tester si le fichier existe
        {
        printf("Impossible d'ouvrir le fichier \n");
        return 0;
        }
      while (fgets(chaine, 1000, f) ) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s\n", chaine); // On affiche la chaîne qu'on vient de lire
        }

        fclose(f);

 }











//----------------------------------------------------------retour au menu principal----------------------------------------------------



void affichageMenu_adh()
{
    int choixMenu;// choix de l'utilisateur


    SetColor(35);//Function call to change the text color
    printf("\n\t\t\t\t-----------------------------------------\n");
     printf("\t\t\t\t1.ajouter un adherent!\n");
     printf("\t\t\t\t2.modifier un adherent!\n");
     printf("\t\t\t\t3. supprimer un adherent!\n");
     printf("\t\t\t\t4.Recherche d un adherent par son nom et affichage du resultat\n");
     printf("\t\t\t\t5-affichage\n");
     printf("\t\t\t\t6.retour au menu principal\n");
     printf("\n\t\t\t\t-----------------------------------------\n");
     printf("\n\t\t\t\tVotre choix?\n\n");
     scanf("%d",&choixMenu);
     printf("\n\n");

     switch(choixMenu)
    {
                     case 1:
                          ajout_adh();

                          break;
                     case 2:
                          modifierAdherent();

                          break;
                     case 3:
                          supp_adh();
                          menu_principal();
                          break;
                     case 4:
                          rech_adherent();
                          menu_principal();
                          break;
                      case 5:
                          affichage_adh();
                          menu_principal();
                          break;
                     case 6:
                          system("cls");
                          menu_principal();
                          break;
                     default:
                         printf("Vous ne ferez rien du tout!");
                         menu_principal();
                         break;
     }

}


