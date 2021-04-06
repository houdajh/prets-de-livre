
#include "myfiles.h"




int main()
{

    printf("\n\n\t\t\t-------------------------------- Le   travail    manuel  est   une  lecture  sans  fin  (pierre gascar)--------------------------------.\n\n");

    bienvenue();
    SetColor(35);
    menu_principal();
    merci();


 return 0;
}


// -----------------menu principal ----------------------------------------------------------------------------------------------------
void menu_principal(){

    int choix;
    printf("\n\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t 1-Gestion des adherents\n");
    printf("\t\t\t\t 2-Gestion des Livres\n");
    printf("\t\t\t\t 3-Gestion des emprunts\n");
    printf("\t\t\t\t 4-fermer le programme\n");
    printf("\n\t\t\t\t-----------------------------------------\n");
    printf("\n\n\t\t\t\t Votre choix?\n\n");

    scanf("%d",&choix);
    system("cls");
    switch(choix){
        case 1:
            emoji();
            affichageMenu_adh();

            break;
        case 2:
            livre_sty();
            affichageMenu_liv();
            break;
        case 3:
            menu_emprunts();
            break;
        case 4:
		   printf ("Vous avez choisi de fermer le programme.");
		   merci();
		   exit(0);
		   break;
        default:
             printf("Vous ne ferez rien du tout!\n");

             break;
    }



}



