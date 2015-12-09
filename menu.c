#include "fonctions.h"

int main(int argc, char *argv[]){

    printf("Bienvenu sur Dictionnaire V2\n\n\n\n");
	int continuer = 1;
	//char *string1 = "bonjour";
	//char *string2;
	char parcoursTrait[MAX_LENGTH] = {'\0'};
  char motATester[MAX_LENGTH];
  char parcoursApp[MAX_LENGTH] = { '\0' };
  char motAAjouter[MAX_LENGTH];
  //char parcoursSuppr[MAX_LENGTH] = { '\0' };
//  char parcoursSupprApp[MAX_LENGTH] = {'\0'};
  char motASupprimer[MAX_LENGTH];
	Dictionnaire actuel=Creer_Dictionnaire();

	while(continuer != 0){
		int choix;
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

            printf("Quel mot voulez-vous supprimer du dictionnaire?\n");
            scanf("%s",motASupprimer);
            actuel=Supprimer_Mot(actuel, motASupprimer);
					break;

					case 3:
					if(actuel!=NULL){
						printf("\nAffichage du Dictionnaire :\n\n");
						Traiter_Dictionnaire(actuel,parcoursTrait,Faux);

					}
					else
						printf("\nLe Dictionnaire est vide ! \n");
					break;

					case 4:
            printf("Quel mot voulez-vous tester ?\n");
            scanf("%s",motATester);
            if(Appartient_Mot(actuel,motATester, parcoursApp)==Vrai){
              printf("Votre mot appartient au dictionnaire actuel !\n");
            }
            else printf("Votre mot n'appartient pas au dictionnaire actuel !\n");
					break;

					case 5:
					break;

					case 6:
    					printf("\nSauvegarde du dictionnaire en cours... \n");
    					Traiter_Dictionnaire(actuel,parcoursTrait,Vrai);

					break;

					case 7:
					printf("\nChargement du dictionnaire en cours... \n");
          if(fopen("dico.algo" , "r")==NULL){
            printf("\nSauvegarde du dictionnaire en cours... \n");
            Traiter_Dictionnaire(actuel,parcoursTrait,Vrai);
          }else{
            actuel=charger(actuel);
            remove("dico.algo");
            Traiter_Dictionnaire(actuel,parcoursTrait,Vrai);
          }
					break;

					case 8: printf("\nAu revoir\n");
						continuer=0;
					break;

					case 9: // Test si dico vide
            //if(debug==0) debug = 1; else debug = 0;
					break;
					default : printf("\n\n\nVeuillez entrer un choix valide\n");
						break;
			}
			break;

			case 2:	// ajouter mot
				printf("\nQuel mot ajouter ?\n");
				scanf("%s",motAAjouter);
        int j=0;
        printf("Mot à ajouter : \n");
        for(j=0;j<MAX_LENGTH;j++){
          printf("%c(%x)",motAAjouter[j],motAAjouter[j]);
        }
        printf("\n");
				actuel=Ajouter_Mot(actuel,motAAjouter);
				printf("\n\n");
				continuer=1;
				break;
			default :
			break;
		}


	}
    return 0;
}
