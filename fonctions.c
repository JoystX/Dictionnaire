#include"fonctions.h"

char *fin_du_mot(char mot[], int index){ // Cree une string qui contient la fin du mot ( à partir de la i-ème lettre )
	int j;
	char *nouveau = malloc (sizeof (char) * (MAX_LENGTH-index )) ;
	for(j=0;j<MAX_LENGTH;j++){
		nouveau[j]=mot[index+j];
	}
	return nouveau;
}

Dictionnaire Creer_Dictionnaire(void){ // Fonctionne
	Dictionnaire D;
	D = (Dictionnaire)malloc(sizeof(*D));
	D->lettre='\0';
	D->PFG=NULL;
	D->PFD=NULL;
	return D;
}
Dictionnaire Ajouter_Mot(Dictionnaire D, char M[]){ // En cours
	char motParcours[MAX_LENGTH] = {'\0'};
	if(!Appartient_Mot(D,M, motParcours)){
		printf("Cactère actuel : %c (%x)\n",M[0],M[0]);
		if(M[0]!='\0'){
			M=minuscule(M);
			if(D==NULL){
				printf("Création noeud\n");
				D=Creer_Dictionnaire();
			}
			printf("Ajout de la lettre \"%c\" (%x) dans le noeud \"%c\" (%x)\n", M[0],M[0],D->lettre,	 D->lettre );

			if(D->lettre=='\0'){
				D->lettre=M[0];
				printf("Lettre %x ajoutée\n",D->lettre);
				printf("On ajoute la suite dans le fils gauche\n" );
				D->PFG=Ajouter_Mot(D->PFG,fin_du_mot(M,1));
			}
			else if(M[0]>D->lettre){
				printf("Lettre plus grande, passage du mot au frère droit\n" );
				D->PFD=Ajouter_Mot(D->PFD, M);
			}
			else if(M[0]<D->lettre){
				printf("Lettre plus petit, passage du mot à gauche ( on décale tout vers la droite )\n" );
				Dictionnaire transition = Creer_Dictionnaire();
				transition->PFD=D;
				transition->lettre=M[0];
				D=transition;
				printf("Ajout de la lettre %x\n",D->lettre);
				D->PFG=Ajouter_Mot(D->PFG,fin_du_mot(M,1));
			}
			else if(M[0]==D->lettre){
				printf("Même lettre, on passe à la suivante \n");
				D->PFG=Ajouter_Mot(D->PFG,fin_du_mot(M,1));
			}
		}
		else {
			printf("Nous sommmes arrivés à la fin du mot\n" );
			if(D==NULL){
				printf("Création noeud\n");
				D=Creer_Dictionnaire();
				printf("Ajout de la lettre \"%c\" (%x) dans le noeud \"%c\" (%x)\n", '*','*',D->lettre,	 D->lettre );
				D->lettre='*';
				printf("Lettre %x ajoutée\n",D->lettre);
			}
			else{
				printf("Le noeud existe déjà, passage de celui-ci au frère droit");
				printf("Noeud actuel : %c (%x)\n",D->lettre,D->lettre);

				Dictionnaire transition = Creer_Dictionnaire();
				transition->PFD=D;
				transition->lettre='*';
				D=transition;
			}
		}
	}
	else{
		printf("Le mot existe déjà\n");
	}
	return D;
}
Dictionnaire Supprimer_Mot(Dictionnaire D, char M[]){
	if(D!=NULL){
			if(M[0]!='\0'){
				printf("Caractère actuel : %c (%x)",D->lettre,D->lettre);
				char motAppartient[MAX_LENGTH] = { '\0' };
				if(Appartient_Mot(D,M,motAppartient)){
					if(M[0]>D->lettre){
						printf("Lettre plus grande, passage du mot au frère droit\n" );
						D->PFD=Supprimer_Mot(D->PFD, M);
					}
					else if(M[0]==D->lettre){
						printf("Même lettre, on passe au fils \n");
						D->PFG=Supprimer_Mot(D->PFG,fin_du_mot(M,1));
						if(D!=NULL){
							printf("Caractère actuel : %c (%x)",D->lettre,D->lettre);
							if(D->PFD==NULL && D->PFG==NULL){
								printf("Remontée : suppression du caractère actuel \n");
								D=NULL;
							}
							else if (D->PFD!=NULL){
								printf("Remontée : transition du frère droit \n");
								Dictionnaire transition = Creer_Dictionnaire();
								transition = D->PFD;
								D=transition;
							}
						}
					}
				}
				else printf("Le dictionnaire ne contient pas ce mot !\n");
			}
			else{
				printf("Nous sommes arrivés à la fin du mot à supprimer\n");
				if(D->lettre=='*'){
					if(D->PFD==NULL){
						printf("Fin du mot : suppression du caractère de fin ('*') \n");
						D=NULL;
					}
					else{
						printf("Fin du mot : transition du frère droit \n");
						Dictionnaire transition = Creer_Dictionnaire();
						transition = D->PFD;
						D=transition;
					}
				}
			}
	}
	else
	printf("Le dictionnaire n'existe pas !\n ");

	return D;
}
char* Traiter_Dictionnaire(Dictionnaire D,char motActuel[], Booleen save){ // Fonctionne
	if(D!=NULL){
		if(!Dictionnaire_Vide(D)){
			int i = 0;
			while(motActuel[i]!='\0'){ // On se place à la fin du mot actuel
				i++;
			}
			if(D->lettre!='*'){ // CONDITION IMPORTANTE !!! : Permet de ne pas lire les '*' à la fin des mots // Desactiver pour debug
				// Ajout de la lettre du noeud actuel
				motActuel[i] = D->lettre;
			}

			if(D->PFG!=NULL){
				Traiter_Dictionnaire(D->PFG,motActuel,save);
			}
			else{ // S'il n'y a pas de fils gauche, c'est qu'on est arrivé au bout d'un mot

				if(save == Vrai){
				enregistrer(motActuel);
				}
				else{
				printf("%s\n",motActuel); // >>> Affichage du mot actuel, puis on remonte jusqu'à un noeud qui a un frère droit en enlevant un caractère à chaque fois
				}

				motActuel[i]='\0';
			}
			if(D->PFD!=NULL){
				Traiter_Dictionnaire(D->PFD,motActuel,save);
			}
			else{
				// S'il n'y a pas de fils droit, on continue à remonter et enlever un caractère à chaque fois
				motActuel[i-1]='\0';
			}
		}
		else printf("Le dictionnaire est vide !\n");
	}
	else
	printf("Le dictionnaire n'existe pas !\n ");

	return 0;
}
Booleen Appartient_Mot(Dictionnaire D,char M[], char motActuel[]){ // En Fonctionne
	Booleen valeur=Faux;
	if(D!=NULL){
		int i = 0;
		while(motActuel[i]!='\0'){ // On se place à la fin du mot actuel
			i++;
		}
	if(D->lettre!='*'){ // CONDITION IMPORTANTE !!! : Permet de ne pas lire les '*' à la fin des mots // Desactiver pour debug
			// Ajout de la lettre du noeud actuel
			motActuel[i] = D->lettre;
	}

		if(D->PFG!=NULL){
			if(valeur == Faux )
			valeur = Appartient_Mot(D->PFG,M,motActuel);
		}
		else{ // S'il n'y a pas de fils gauche, c'est qu'on est arrivé au bout d'un mot
			if(strcmp(M,motActuel)==0){
				int i = 0;
				for(i=0;i<MAX_LENGTH;i++){
					 motActuel[i]='\0';
				 }
				 valeur = Vrai;

			 }
			motActuel[i]='\0';
		}
		if(D->PFD!=NULL){
			if( valeur == Faux )
			 valeur = Appartient_Mot(D->PFD,M,motActuel);
		}
		else{
			// S'il n'y a pas de fils droit, on continue à remonter et enlever un caractère à chaque fois
			motActuel[i-1]='\0';
		}
	}
	else
	printf("Dictionnaire vide !\n ");
	return valeur;
}

Booleen Dictionnaire_Vide(Dictionnaire D){ // En cours
	if(D==NULL){
		return Vrai;
	}
	else{
		if(D->lettre=='\0'){
			return Vrai;
		}
		else return Faux;
	}
	return Faux;
}

char * minuscule (char mot[]){ // Focntion vérifiant les mots entrés par l'utilisateur.

	int i=0;

	while(mot[i]!='\0'){			// On analyse entierement le mot
	if(mot[i]>122 || mot[i]<97 ){		// Si le mot est un caractère différents de a à z
		if(mot[i]<91 && mot[i]>64){		// Soit le mot comporte une majuscule
		mot[i]=mot[i]+32;				// On le met en minuscule
		}
		else{
		printf("Votre mot comporte des caracteres autre que des lettres.\n");	// Soit le mot comporte un caractere complétement différents de a-z, A-Z
		exit(1);
		}
	}
	i++;
	}
	return mot;
}

void enregistrer (char  M[]){ // Fonction d'enregistrement du dictionnaire

	FILE *flo1 = NULL;
	flo1 = fopen("dico.algo", "a+");	// On ouvre le fichier en fin de curseur

	if ( flo1 == NULL)
	{
		printf(" Le dictionnaire ne peut être enregistré.\n");	// Si le fichier n'est pas accessible
	}
	else{
		printf("Mot enregistré : %s \n",M);	// Sinon, on enregistre le mot
		fprintf(flo1,"%s\n",M);	// Ajout du mot
		}
		fclose(flo1);	// On referme le flux
}

Dictionnaire charger (Dictionnaire D){	// Fonction chargeant un dictionnaire
	if(D->lettre!='\0'){
		int choix=0;
		while(choix==0){
			printf("Votre dictionnaire n'est pas vide. Voulez-vous l'écraser lors du chargement ou fusionner les deux ?\n");
			printf("1- Ecraser le dictionnaire actuel\n");
			printf("2- Fusionner le dictionnaire actuel et celui contenu dans le fichier\n");
			scanf("%d",&choix);
			if(choix==1){
				D=Creer_Dictionnaire();
			}
			else if(choix==2){

			}else{
				printf("Choix invalide\n");
				choix=0;
			}
		}
	}

	FILE *flo1 = NULL;
	flo1=fopen("dico.txt","r");	// Ouverture du dictionnaire en lecture seule
	char TempMot[MAX_LENGTH];		//Mot tempon

	if (flo1 == NULL){
		printf("Le dictionnaire ne peut être chargé.\n");	// Si on ne peut pas ouvrir le dictionnaire
	}
	else{

		while (fgets(TempMot, MAX_LENGTH, flo1) != NULL )			// Tant que l'on est pas arrivé à la fin de fichier
		{

									int j=0;
									printf("Mot à ajouter : \n");
									for(j=0;j<MAX_LENGTH;j++){
										if(TempMot[j]=='\n'){
											//printf("Retour chariot trouvé\n" );
											TempMot[j]='\0';
										}
										printf("%c(%x)",TempMot[j],TempMot[j]);
									}
									printf("\n");
		               		// On lis la chaîne de caractère et on déplace le curseur à la fin
									 printf("\nTransfert du mot %s dans le dictionnaire actuel\n\n",TempMot);
									 D=Ajouter_Mot(D, TempMot);			// On ajoute alors le mot au dictionnaire
		               printf("\nLe mot %s a été chargé. \n\n", TempMot);
		}
		fclose(flo1);	// On ferme le flux
	}
	return D;

}
