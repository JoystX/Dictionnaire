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
		if(D==NULL){
			printf("création noeud\n");
			D=Creer_Dictionnaire();
		}
		if(D->lettre=='\0'){
			D->lettre=M[0];
			printf("ajout de la lettre %c\n",D->lettre);
			printf("Ajout du mot %s dans le PFG\n",fin_du_mot(M,1));
			Ajouter_Mot(D->PFG,fin_du_mot(M,1));
		}
		else if(M[0]>D->lettre){
			Ajouter_Mot(D->PFD, M);
		}
		else if(M[0]<D->lettre){
			D->PFD=D;
			Ajouter_Mot(D->PFG,M);
		}
		else if(M[0]==D->lettre){
			Ajouter_Mot(D->PFG,fin_du_mot(M,1));	
		}
	}
	return D;
}
Dictionnaire Supprimer_Mot(Dictionnaire D,char M[]){
	return D;
}
void Afficher_Dictionnaire(Dictionnaire D,char motActuel[]){ // Fonctionne 
	if(D!=NULL){
		int i = 0;
		while(motActuel[i]!='\0'){
			i++;
			}
		//printf("Ajout d'une lettre\n");
		motActuel[i] = D->lettre;
		if(D->PFG!=NULL){
			//printf("On descend \n");
			Afficher_Dictionnaire(D->PFG,motActuel);
		}
		else{
			printf("%s",motActuel);
			motActuel[i]='\0';
		}
		printf("\n");
		if(D->PFD!=NULL){
			//printf("On va à droite \n");
			Afficher_Dictionnaire(D->PFD,motActuel);
		}
		else{
			//printf("Retrait d'une lettre");
			motActuel[i-1]='\0';
		}
	}
	else
	printf("Dictionnaire vide !\n ");
}
Booleen Appartient_Mot(Dictionnaire D,char M[]){ // Pas commencé
	return Faux;
}
Booleen Dictionnaire_Vide(Dictionnaire D){ // Pas commencé
	return Faux;
}

