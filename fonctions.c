#include"fonctions.h"

char *fin_du_mot(char mot[], int index){ // Cree une string qui contient la fin du mot ( à partir de la i-ème lettre )
	int j;
	char *nouveau = malloc (sizeof (char) * (MAX_LENGTH-index )) ;
	for(j=0;j<MAX_LENGTH;j++){
		nouveau[j]=mot[index+j];
	}
	return nouveau;
}

Dictionnaire Creer_Dictionnaire(void){
	Dictionnaire D;
	D = (Dictionnaire)malloc(sizeof(*D));
	return D;
}
Dictionnaire Ajouter_Mot(Dictionnaire D, char M[]){
	if(D==NULL){
		D=Creer_Dictionnaire();
	}
	int i;
	for(i=0;i<MAX_LENGTH;i++){ // On parcourt chaque lettre du mot
		Ajouter_Mot(D->PFG,fin_du_mot(M,i);
		
			
	}
	return D;
}
Dictionnaire Supprimer_Mot(Dictionnaire D,char M[]){
	return D;
}
void Afficher_Dictionnaire(Dictionnaire D){
	if(D!=NULL){
		printf(D->lettre);
		Afficher_Dictionnaire(PFG);
		printf("\n");
		Afficher_Dictionnaire(PFD);
	}
}
Booleen Appartient_Mot(Dictionnaire D,char M[]){
	return Faux;
}
Booleen Dictionnaire_Vide(Dictionnaire D){
	return Faux;
}

