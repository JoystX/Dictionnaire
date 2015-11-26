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
char* Afficher_Dictionnaire(Dictionnaire D,char motActuel[], Booleen save){ // Fonctionne
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
			Afficher_Dictionnaire(D->PFG,motActuel,save);
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
			Afficher_Dictionnaire(D->PFD,motActuel,save);
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

char * minuscule (char mot[]){ // Fonctionne
	
	int i=0;
	
	while(mot[i]!='\0'){
	if(mot[i]>122 || mot[i]<97 ){
		if(mot[i]<91 && mot[i]>64){
		mot[i]=mot[i]+32;
		}
		else{
		printf("Votre mot comporte des caracteres autre que des lettres.\n");
		exit(1);
		}
	}
	i++;
}
	
	
	
	
return mot;
}

void enregistrer (char  M[]){

	FILE *flo1 = NULL;
flo1 = fopen("dico.algo", "a+");	

if ( flo1 == NULL)
{
	printf(" Le dictionnaire ne peut être enregistré.\n");
    exit(2);
}
else{
	printf("Mot enregistré : %s \n",M);
	fprintf(flo1,"%s\n",M);
	}
	fclose(flo1);
}
