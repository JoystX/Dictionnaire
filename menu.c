#include"fonctions.h"

int main()
{
    
    printf("Bienvenu sur Dictionnaire V2\n\n\n\n");
	int continuer = 1;
	while(continuer == 1){
		int choix;
		printf("Choisissez votre option :\n\n");

		printf("1- Ajouter un mot\n");
		printf("2- Supprimer un mot\n");
		printf("3- Afficher le contenu du dictionnaire\n");
		printf("4- Tester si un mot appartient au dictionnaire\n");
		printf("5- Vider le dictionnaire\n");
		printf("6- Sauvegarder le contenu du dictionnaire dans fichier\n");
		printf("7- Charger un dictionnaire � partir d'un fichier\n");
		printf("8- Quitter\n");

		switch (choix){
			case 1:
			break;

			case 2:
			break;

			case 3:
			break;

			case 4:
			break;

			case 5:
			break;

			case 6:
			break;

			case 7:
			break;

			case 8: printf("Au revoir");
			break;

			default : printf("\n\n\nVeuillez entrer un choix valide\n");
				break;

		}


		scanf("%d",&choix);
	}
    return 0;
}

//Dictionnaire Creer_Dictionnaire {return Dictionnaire;}
//Ajouter_Mot(Dictionaire dico1, Mot mot1) {return Dictionnaire;}
//Supprimer_Mot(Dictionnaire dico1,Mot mot){return Dictionnaire;}
//Appartient_Mot(Dictionnaire dico1, Mot mot1){reutrn boolen a}
//Afficher_Dictionnaire
//Vider_Dictionnaire(Dictionnaire dico1)
//Save_Dictionnaire
//Charger dictionnaire
