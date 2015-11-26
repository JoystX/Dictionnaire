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
	return D;
}
Dictionnaire Ajouter_Mot(Dictionnaire D, char M[]){ // En cours
	if(M[0]!='\0'){
		M=minuscule(M);
		if(D==NULL){
			printf("Création noeud\n");
			D=Creer_Dictionnaire();
		}
		if(D->lettre=='\0'){
			D->lettre=M[0];
			printf("Ajout de la lettre %x\n",D->lettre);
			printf("Ajout du mot %s dans le PFG\n",fin_du_mot(M,1));
			D->PFG=Ajouter_Mot(D->PFG,fin_du_mot(M,1));
		}
		else if(M[0]>D->lettre){
			printf("Pa1ssage du mot au frère droit\n" );
			D->PFD=Ajouter_Mot(D->PFD, M);
		}
		else if(M[0]<D->lettre){
			printf("Passage du mot à gauche ( on décale tout vers la droite )\n" );
			Dictionnaire transition = Creer_Dictionnaire();
			transition->PFD=D;
			transition->lettre=M[0];
			D=transition;
			printf("Ajout de la lettre %x\n",D->lettre);
			printf("Ajout du mot %s dans le PFG\n",fin_du_mot(M,1));
			D->PFG=Ajouter_Mot(D->PFG,fin_du_mot(M,1));
		}
		else if(M[0]==D->lettre){
			printf("Même lettre, on passe à la suivante \n");
			D->PFG=Ajouter_Mot(D->PFG,fin_du_mot(M,1));
		}
	}
	else {
		if(D==NULL){
			D=Creer_Dictionnaire();
			D->lettre='*';
			printf("Ajout de la lettre %x\n",D->lettre);
		}
		else{
			Dictionnaire transition = Creer_Dictionnaire();
			transition->PFD=D;
			transition->lettre='*';
			D=transition;
		}
	}
	return D;
}
Dictionnaire Supprimer_Mot(Dictionnaire D,char M[]){
	return D;
}
char* Traiter_Dictionnaire(Dictionnaire D,char motActuel[], Booleen save){ // Fonctionne
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
	else
	printf("Dictionnaire vide !\n ");

	return 0;
}
Booleen Appartient_Mot(Dictionnaire D,char M[]){ // Pas commencé



	return Faux;
}
Booleen Dictionnaire_Vide(Dictionnaire D){ // Pas commencé
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
    exit(2);
}
else{
	printf("Mot enregistré : %s \n",M);	// Sinon, on enregistre le mot
	fprintf(flo1,"%s\n",M);	// Ajout du mot
	}
	fclose(flo1);	// On referme le flux
}

void charger (Dictionnaire D){	// Fonction chargeant un dictionnaire

	FILE *flo1 = NULL;
	flo1=fopen("dico.algo","r");	// Ouverture du dictionnaire en lecture seule
	char TempMot[MAX_LENGTH];		//Mot tempon

	if (flo1 == NULL){
		printf("Le dictionnaire ne peut être chargé.\n");	// Si on ne peut pas ouvrir le dictionnaire
	}
	else{

	while (fscanf(flo1,"%s",TempMot) == 1)			// Tant que l'on est pas arrivé à la fin de fichier
	{
	               		// On lis la chaîne de caractère et on déplace le curseur à la fin
								 printf("Transfert du mot %s dans le dictionnaire actuel\n",TempMot);
								 Ajouter_Mot(D, TempMot);			// On ajoute alors le mot au dictionnaire
	               printf(" Le mot %s à été chargé. \n", TempMot);
	}
	fclose(flo1);	// On ferme le flux
	}

}
