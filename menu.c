#include"fonctions.h"

int main(int argc, char *argv[])
{
    
    printf("Bienvenu sur Dictionnaire V2\n\n\n\n");
	int continuer = 1;
	char *string1 = "bonjour";
	char *string2;
	char motAffichage[MAX_LENGTH] = {'\0'};
	Dictionnaire actuel=NULL;//=Creer_Dictionnaire();
	
	// DICO DE TEST ( celui du cours et du sujet ). Dé-commenter pour tester ( ne pas oublier Creer-Dictionnaire juste au dessus )
	/*actuel->lettre='c';
	actuel->PFG=Creer_Dictionnaire();	
	actuel->PFG->lettre='a';
	actuel->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->lettre='o';
	actuel->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->lettre='l';
	actuel->PFG->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->lettre='\0';
	actuel->PFG->PFD->PFG->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->lettre='l';
	actuel->PFG->PFD->PFG->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->lettre='i';
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->lettre='n';
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFD->lettre='s';
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFG->lettre='e';
	actuel->PFG->PFD->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFD->lettre='u';
	actuel->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFG->lettre='\0';
	actuel->PFG->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFG->PFD->lettre='l';
	actuel->PFG->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFG->PFD->PFG->lettre='e';*/
	
	while(continuer != 0){
		int choix;
		char mot[MAX_LENGTH];
		switch(continuer){
			case 1:
				printf("Choisissez votre option :\n\n");

				printf("1- Ajouter un mot\n");
				printf("2- Supprimer un mot\n");
				printf("3- Afficher le contenu du dictionnaire\n");
				printf("4- Tester si un mot appartient au dictionnaire\n");
				printf("5- Vider le dictionnaire\n");
				printf("6- Sauvegarder le contenu du dictionnaire dans fichier\n");
				printf("7- Charger un dictionnaire à partir d'un fichier\n");
				printf("8- Quitter\n");
				printf("9 - Test \n");

				scanf("%d",&choix);

				switch (choix){
					case 1:
						continuer = 2;

					break;

					case 2:
					break;

					case 3:
					if(actuel!=NULL){
						printf("\nAffichage du Dictionnaire :\n\n");
						Afficher_Dictionnaire(actuel,motAffichage);
						
					}
					else
						printf("\nLe Dictionnaire est vide ! \n");
					break;

					case 4:
					break;

					case 5:
					break;

					case 6:
					break;

					case 7:
					break;

					case 8: printf("\nAu revoir\n");
						continuer=0;
					break;
					
					case 9: // Test fonction fin_du_mot
						
						printf("%s",motAffichage);
					break;
					default : printf("\n\n\nVeuillez entrer un choix valide\n");
						break;
			}
			break;
			
			case 2:	// ajouter mot
				printf("\nQuel mot ajouter ?\n");
				scanf("%s",mot);
				actuel=Ajouter_Mot(actuel,mot);
				printf("\n\n");
				continuer=1;
				break;
			default :
			break;
		}


	}
    return 0;
}
