//----------------------------------------livres----------------------------------------------------------------------------------------
#include "myfiles.h"




//fonction auxiliaire : il cherche si le numero du livre existe deja
bool recherche_liv(int numrech)
{
	livre liv;
	FILE *fich=NULL;
	fich=fopen("livres.txt","r");//(en mode lecture)c'est pas la peine d'ecrire un chemin physique car mon fichier et le projet sont dans le meme repertoire
	if(fich==NULL)//tester si le fichier existe
        {
        printf("Impossible d'ouvrir le fichier \n");
        return 0;
        }
	do{
		fscanf(fich,"%d #%s #%s #%s #%s #%d",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
		fflush(stdin);// pour liberer la memoire
		if (liv.num_liv==numrech){
			fclose(fich);
			return true;// on a trouvé le numero du livre dans le fichier
		}
	}while (!feof(fich));
	fclose(fich);
	return false;

}









//---------------------------------------------ajout_liv------------------------------------------------------------------------


void ajout_liv(){
	livre liv;// liv variable de type livre
	FILE *fich=NULL;
	int num,x;
	fich=fopen("livres.txt","a");// ouvrir en mode d'ajout
	if(fich==NULL)//tester si le fichier existe
        {
        printf("Impossible d ouvrir le fichier \n");
        return 0;
        }
        do{
	printf("entrer le numero du nouveau livre:\n");
	printf("le numero doit etre strictement positif\n");
	scanf("%d",&num);
	fflush(stdin);
        }while(num<=0);
	while(recherche_liv(num)){// si le livre existe deja dans le fichier(chaque livre a un numero unique)
		printf("ce livre est deja exister\n");
		printf("entrer le numero du livre \n");
		scanf("%d",&num);
	}
	//recuperer les informations
	liv.num_liv=num;
	printf("donner le titre\n ");
    gets(liv.titre_liv);
    fflush(stdin);
    printf("donner la categorie\n");
    printf("1-scientifique \n 2-litterature \n 3-religion \n 4-informatique \n 5-arts \n 6-cuisine \n 7-droit \n 8-philosophie \n 9-fiction \n 10-histoire\n");
    printf("votre choix ?\n");// choisir l'un des categories
    scanf("%d",&x);
    fflush(stdin);
    switch(x){//recuperer liv.categ_liv
    case 1:
        strcpy(liv.categ_liv,"scientifique");
        break;
    case 2:
        strcpy(liv.categ_liv,"litterature");
        break;
    case 3:
        strcpy(liv.categ_liv,"religion");
        break;
    case 4:
        strcpy(liv.categ_liv,"informatique");
        break;
    case 5:
        strcpy(liv.categ_liv,"arts");
        break;
    case 6:
        strcpy(liv.categ_liv,"cuisine");
        break;
    case 7:
        strcpy(liv.categ_liv,"droit");
        break;
    case 8:
        strcpy(liv.categ_liv,"philosophie");
        break;
    case 9:
        strcpy(liv.categ_liv,"fiction");
        break;
    case 10:
        strcpy(liv.categ_liv,"histoire");
        break;
    default:
        printf("choisir l'un de ces choix\n");// pour uniformiser les categories il faut choisir l'un de ces choix
        affichageMenu_liv();// revenu au menu
        break;

    }

    printf("donner le nom de l'auteur\n");
    gets(liv.aut.nom_aut);
    fflush(stdin);
    printf("donner le prenom de l auteur\n");
    gets(liv.aut.prenom_aut);
    fflush(stdin);
    do{
    printf("dooner un numero qui comprend le numero de l adherent\n ");
    printf("donner un -1 si ce livre est disponible\n");
    scanf("%d",&(liv.emprunteur_liv));
    fflush(stdin);
    }while(liv.emprunteur_liv<-2);
    if(!(recherche_adh(liv.emprunteur_liv)) && liv.emprunteur_liv!=-1){ //num_adh==emprunteur_liv
        printf("cet adherent n'existe pas parmi nos donnees\n");
        affichageMenu_liv();
    }
    // ajouter la ligne dans le fichier
	fprintf(fich,"%d #%s #%s #%s #%s #%d\n",liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,liv.emprunteur_liv);
	fflush(stdin);
	fclose(fich);// fermer le fichier

}









//---------------------------------------------modifierlivre------------------------------------------------------------------------


void modifierlivre(){
livre liv;//liv:variable de type livre
FILE*F,*fich;
int num,i,x;
char rep='n';
printf("\n entrer le numero du livre a modifier :");
scanf("%d",&num);
fflush(stdin);
if(recherche_liv(num)){// si le numero du livre  existe dans le fichier on va le modifier
    do{
    printf("\n voulez vous vraiment modifier o|n?");//les précautions
    scanf("%c",&rep);
    fflush(stdin);
 }while(!(rep=='o' || rep=='n' || rep=='N' || rep=='O' ));
    printf("%c",rep);
    if(rep=='o' || rep=='O'){
        F=fopen("livres.txt","r"); // OUVRIR en mode lecture
        fich=fopen("tempLivre.txt","a"); // OUVRIR en mode l'ajout
          if(F==NULL ) //tester si le fichier existe
        {
        printf("Impossible d'ouvrir le fichier \n");
        return 0;
        }
        do{
                // pour recuperer les donnes
           fscanf(F,"%d #%s #%s #%s #%s #%d \n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
           if(num==liv.num_liv){// si on a trouver notre choix
            liv.num_liv=num;
	printf("donner le titre\n ");
    gets(liv.titre_liv);
    fflush(stdin);
     printf("donner la categorie\n");
    printf("1-scientifique \n 2-litterature \n 3-religion \n 4-informatique \n 5-arts \n 6-cuisine \n 7-droit \n 8-philosophie \n 9-fiction \n 10-histoire\n");
    printf("votre choix ?\n");// choisir l'un des categories
    scanf("%d",&x);
    fflush(stdin);
    switch(x){//recuperer liv.categ_liv
    case 1:
        strcpy(liv.categ_liv,"scientifique");
        break;
    case 2:
        strcpy(liv.categ_liv,"litterature");
        break;
    case 3:
        strcpy(liv.categ_liv,"religion");
        break;
    case 4:
        strcpy(liv.categ_liv,"informatique");
        break;
    case 5:
        strcpy(liv.categ_liv,"arts");
        break;
    case 6:
        strcpy(liv.categ_liv,"cuisine");
        break;
    case 7:
        strcpy(liv.categ_liv,"droit");
        break;
    case 8:
        strcpy(liv.categ_liv,"philosophie");
        break;
    case 9:
        strcpy(liv.categ_liv,"fiction");
        break;
    case 10:
        strcpy(liv.categ_liv,"histoire");
        break;
    default:
        printf("choisir l'un de ces choix\n");// pour uniformiser les categories il faut choisir l'un de ces choix
        affichageMenu_liv();// revenu au menu
        break;

    }

    printf("donner le nom de l'auteur\n");
    gets(liv.aut.nom_aut);
    fflush(stdin);
    printf("donner le prenom de l'auteur\n");
    gets(liv.aut.prenom_aut);
    fflush(stdin);
        do{
    printf("dooner un numero qui comprend le numero de l adherent\n ");
    printf("\ndonner un -1 si ce livre est disponible\n");
    scanf("%d",&(liv.emprunteur_liv));
    fflush(stdin);
    }while(liv.emprunteur_liv<-2);
    if(!(recherche_adh(liv.emprunteur_liv)) && liv.emprunteur_liv!=-1){ //num_adh==emprunteur_liv
        printf("cet adherent n'existe pas parmi nos donnees\n");
        affichageMenu_liv();
    }

    }
    // ajouter la ligne dans le fichier temporaire
    fprintf(fich,"%d #%s #%s #%s #%s #%d\n",liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,liv.emprunteur_liv);

        }while(!feof(F));
        fclose(F);//fermer les deux fechiers
        fclose(fich);
        remove("livres.txt");// supprimer les anciennes informations
        rename("tempLivre.txt","livres.txt");// renommer le fichier qui contient les informationd desirees
        printf("\n modification effectuer avec success ");
        return;
    }
    else{
        printf("\la modification est annulée\n");// on a choisit 'n'
    }
}
else{
    printf("\nce livre n'existe pas\n");// recherche_liv return false
}
}
















//---------------------------------------------supp_liv--------------------------------------------------------------------------------


void supp_liv(){

	livre liv;// liv variable de type livre
	char rep;// la reponse du l'utilisateur o/n
	int numrech;
	printf("entrer le nombre du livre a surpprimer:\n");// le nombre du livre est unique
	scanf("%d",&numrech);
	fflush(stdin);
	if(recherche_liv(numrech)){// si le numero est vraiment existe dans le fichier des donnees
        do{
		printf("voulez vous vraiment supprimer o/n:\n");
		scanf("%c",&rep);
		fflush(stdin);
        }while(!(rep=='o' || rep=='n' || rep=='N' || rep=='O' ));// soit oui soit non
		if(rep=='o'|| rep =='O'){// si oui

			FILE *fiche=NULL,*fe=NULL;
			fe=fopen("livres.txt","r");// mode lecture (comme on veut supprimer alors le fichier est non vide)
			fiche=fopen("temps_livres.txt","a");// c'est un fichier temporaire
        if (fe==NULL)            // Test d'ouverture du fichier
    {
        printf("Erreur d'ouverture du fichier");
        return EXIT_SUCCESS;
    }
      do{
            //recuperer nos donnees
             fscanf(fe,"%d #%s #%s #%s #%s #%d \n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));

			if(numrech!=liv.num_liv){// si la ligne contient le livre qu'on ne veut pas le supprimer on va l'ajouter dans le fichier temporaire
                fprintf(fiche,"%d #%s #%s #%s #%s #%d\n",liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,liv.emprunteur_liv);

			}
			}while(!feof(fe));// parcourir tous le fichier
			fclose(fiche);// fermer les deux fichiers
			fclose(fe);
			remove("livres.txt");// supprimer l'ancien fichier
			rename("temps_livres.txt","livres.txt");// renommer le nouveau fichier
			printf("la suppression est effectuée avec succés");
		}
		else{
			printf("la suppression est annulée \n");// l'utilisateur a choisit non
		}

	}
	else{
		printf("ce numero n'existe pas\n");// le numero n'existe pas parmi nos donnees
	}

}











//--------------------------------ordonner_Liv-----------------------------------------------------------------------------------------
void ordonner_Liv(){
livre liv;//liv variable de type livre
int j=0;
FILE *fich=NULL,*fe=NULL;
fe=fopen("livres.txt","r");
fich=fopen("temps_livres.txt","a");// fichier temporaire
if (fe==NULL)            // Test d'ouverture du fichier
    {
        printf("Erreur d'ouverture du fichier");
        return EXIT_SUCCESS;
    }
char *temp;// c'est seulement pour faire la permutation
char* T[]={"scientifique","litterature","religion","informatiquee","arts","cuisine","droit","philosophie","fiction","histoire"};// on stoque tous nos categories
for (int i = 0; i <10; i++) {
    for (int j = 0; j <=sizeof(T[i]); j++){
      if (strcmp(T[i],T[j]) < 0)// code ASCII de T[i] est inferieur de T[j]
        {
            // permuter
          temp =T[i];
          T[i] =T[j];
          T[j] = temp;
        }
    }
}
while(j<10){
        rewind(fe);// remettre le cursseur au debut du fichier
        while(1){
        fflush(stdin)  ;// liberer la memoire
        // recuperer nos informations
        fscanf(fe,"%d #%s #%s #%s #%s #%d \n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));

        if(strcmp(T[j],liv.categ_liv-'\0')==0){ // le tableu T est maintenent ordonné
                // ajouter les lignes dans le fichier temporaire en respectant la priorité
            fprintf(fich,"%d #%s #%s #%s #%s #%d\n",liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,liv.emprunteur_liv);
            //affichage
            printf("%d         %s         %s         %s         %s         %d\n",liv.num_liv,liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,liv.emprunteur_liv);
            fflush(stdin);

        }
        if(feof(fe)) break; // pour sortir de la boucle while(1)
        }
        j++; // pour parcourir T


            }

    fclose(fich);// fermer les deux fichier
    fclose(fe);
    remove("livres.txt");// supprimer les anciennes données
    rename("temps_livres.txt","livres.txt"); // le fichier temporaire devient le fichier principal
    printf("\n\nl'operation est effectué avec succés\n");

}















//-----------------------------------------------rech_Livre----------------------------------------------------------------------------

void rech_livre(){
    int choix,c;
    char categ[20] ,titre[20];
    livre liv;
	FILE *f;
	f=fopen("livres.txt","r");
	do{
	printf("taper :\n 1 pour la recherche par categorie \n  2 pour la recherche par titre \n ");
    scanf("%d",&choix);
    fflush(stdin);  }
	 while (choix!= 1 && choix !=2);
	switch(choix){
        case 1:
        {printf("entrer la categorie\n");
        fflush(stdin);
        gets(categ);
        c=0;
        printf("les titres des livres de categorie %s sont: \n ",categ);
        while(1){
        fflush(stdin)  ;
        fscanf(f,"%d #%s #%s #%s #%s #%d \n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
        if (!strcmp(liv.categ_liv,categ)){
            printf("%s\n",liv.titre_liv);
            c++ ;
			}
         if(feof(f)) break;

            }
        if(c==0) printf("introuvable !!");break;


       fflush(stdin); }
   case 2 :
    {
        {printf("entrer le titre\n");
        fflush(stdin);
        gets(titre);
        c=0;
        while (1){


		fscanf(f,"%d #%s #%s #%s #%s #%d \n",&(liv.num_liv),liv.titre_liv,liv.categ_liv,liv.aut.nom_aut,liv.aut.prenom_aut,&(liv.emprunteur_liv));
		if (!strcmp(liv.titre_liv,titre)){
			printf("ce livre existe \n ");

			return ; }
        if(feof(f)) break;
       }
       fclose(f);
        printf("introuvable !!\n"); }
    }
   }
}




 //----------------------------------------------affichage----------------------------------------------------------------------------

 void affichage_liv(){
    FILE *f=NULL;
    char chaine[1000]="";
    f=fopen("livres.txt","r");
    if(f==NULL) //tester si le fichier existe
        {
        printf("Impossible d'ouvrir le fichier \n");
        return 0;
        }
      while (fgets(chaine, 1000, f) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s\n", chaine); // On affiche la chaîne qu'on vient de lire
        }

        fclose(f);

 }











// -----------------menu_liv ----------------------------------------------------------------------------------------------------
void affichageMenu_liv(){
    int choixMenu;

    SetColor(35);//Function call to change the text color
    printf("\n\t\t\t\t-----------------------------------------\n");
     printf("\t\t\t\t1. ajouter un livre!\n");
     printf("\t\t\t\t2. modifier les informations d'un livre!\n");
     printf("\t\t\t\t3. supprimer un livre!\n");
     printf("\t\t\t\t4. Ordonner les livres par Catégorie!\n");
     printf("\t\t\t\t5. Recherche d’un livre par Catégorie et titre du livre!\n");
     printf("\t\t\t\t6-affichage\n");
     printf("\t\t\t\t7.retour au menu principal\n");
     printf("\n\t\t\t\t-----------------------------------------\n");
     printf("\nVotre choix?\n\n");
     scanf("%d",&choixMenu);

     printf("\n\n");
     switch(choixMenu){
                     case 1:
                          ajout_liv();
                          menu_principal();
                          break;
                     case 2:
                          modifierlivre();

                          break;
                     case 3:
                          supp_liv();
                          menu_principal();
                          break;
                     case 4:
                          ordonner_Liv();
                          menu_principal();
                          break;
                     case 5:
                          rech_livre();
                          menu_principal();
                          break;
                      case 6:
                          affichage_liv();
                          menu_principal();
                          break;
                     case 7:
                         system("cls");
                          menu_principal();
                          break;
                     default:
                         printf("Vous ne ferez rien du tout!");
                         menu_principal();
                         break;
     }
}


