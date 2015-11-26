#include "fonctions.h"

int main(int argc, char *argv[])
{

    printf("Bienvenu sur Dictionnaire V2\n\n\n\n");
	int continuer = 1;
	//char *string1 = "bonjour";
	//char *string2;
	char motAffichage[MAX_LENGTH] = {'\0'};
	char motTest[MAX_LENGTH] = "coucou";
	Dictionnaire actuel=Creer_Dictionnaire();
   // Dictionnaire actuelTransition = NULL;//Creer_Dictionnaire();



	// DICO DE TEST ( celui du cours et du sujet ). D�-commenter pour tester ( ne pas oublier Creer-Dictionnaire juste au dessus )
 /* printf("( Dico du cours )\n");
	actuel->lettre='c';
	actuel->PFG=Creer_Dictionnaire();
	actuel->PFG->lettre='a';
  actuel->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFG->lettre='*'; // Fin de ca*
  actuel->PFG->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFG->PFD->lettre='l';
	actuel->PFG->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFG->PFD->PFG->lettre='e';
  actuel->PFG->PFG->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFG->PFD->PFG->PFG->lettre='*'; // Fin de cale*
	actuel->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->lettre='o';
	actuel->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->lettre='l';
	actuel->PFG->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->lettre='*'; // Fin de col*
	actuel->PFG->PFD->PFG->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->lettre='l';
	actuel->PFG->PFD->PFG->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->lettre='i';
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->lettre='n';
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFG->lettre='e';
  actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFG->PFG->lettre='*'; // Fin de colline*
  actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFD->lettre='s';
  actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFG->PFD->PFG->PFG->PFD->PFG->lettre='*'; // Fin de collis*
	actuel->PFG->PFD->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFD->lettre='u';
  actuel->PFG->PFD->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFD->PFG->lettre='r';
  actuel->PFG->PFD->PFG->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFD->PFG->PFG->lettre='s';
  actuel->PFG->PFD->PFG->PFD->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFD->PFG->PFG->PFG->lettre='*'; // Fin de cours*
  actuel->PFG->PFD->PFG->PFD->PFG->PFD=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFD->PFG->PFD->lettre='t';
  actuel->PFG->PFD->PFG->PFD->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFG->PFD->PFG->PFD->PFG->PFD->PFG->lettre='*'; // Fin de cout*
  //Partie de droite ( T )
  actuel->PFD=Creer_Dictionnaire();
	actuel->PFD->lettre='t';
  actuel->PFD->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->lettre='a';
  actuel->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFG->lettre='r';
  actuel->PFD->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFG->PFG->lettre='t';
  actuel->PFD->PFG->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFG->PFG->PFG->lettre='e';
  actuel->PFD->PFG->PFG->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFG->PFG->PFG->PFG->lettre='*'; // Fin de tarte*
  actuel->PFD->PFG->PFD=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->lettre='i';
  actuel->PFD->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFG->lettre='e';
  actuel->PFD->PFG->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFG->PFG->lettre='r';
  actuel->PFD->PFG->PFD->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFG->PFG->PFG->lettre='c';
  actuel->PFD->PFG->PFD->PFG->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFG->PFG->PFG->PFG->lettre='e';
  actuel->PFD->PFG->PFD->PFG->PFG->PFG->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFG->PFG->PFG->PFG->PFG->lettre='*'; // Fin de tierce*
  actuel->PFD->PFG->PFD->PFD=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFD->lettre='o';
  actuel->PFD->PFG->PFD->PFD->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFD->PFG->lettre='i';
  actuel->PFD->PFG->PFD->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFD->PFG->PFG->lettre='*'; // Fin de toi*
  actuel->PFD->PFG->PFD->PFD->PFG->PFD=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFD->PFG->PFD->lettre='t';
  actuel->PFD->PFG->PFD->PFD->PFG->PFD->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFD->PFG->PFD->PFG->lettre='*'; // Fin de tot*
  actuel->PFD->PFG->PFD->PFD->PFG->PFD->PFD=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFD->PFG->PFD->PFD->lettre='u';
  actuel->PFD->PFG->PFD->PFD->PFG->PFD->PFD->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFD->PFG->PFD->PFD->PFG->lettre='t';
  actuel->PFD->PFG->PFD->PFD->PFG->PFD->PFD->PFG->PFG=Creer_Dictionnaire();
	actuel->PFD->PFG->PFD->PFD->PFG->PFD->PFD->PFG->PFG->lettre='*';  */


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
				printf("7- Charger un dictionnaire � partir d'un fichier\n");
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
						Afficher_Dictionnaire(actuel,motAffichage,Faux);

					}
					else
						printf("\nLe Dictionnaire est vide ! \n");
					break;

					case 4:
					break;

					case 5:
					break;

					case 6:
					printf("\n Sauvegarde du dictionnaire en cours... \n");
					Afficher_Dictionnaire(actuel,motAffichage,Vrai);

					break;

					case 7:
					printf("\n Chargement du dictionnaire en cours... \n");
					charger(actuel);
					break;

					case 8: printf("\nAu revoir\n");
						continuer=0;
					break;

					case 9: // Test fonction fin_du_mot

						printf("Mot avant : %s",motTest);
						printf("Mot apr�s : %s",motTest);
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
