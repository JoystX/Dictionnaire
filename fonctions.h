#include <stdio.h>
#include <stdlib.h>

#define bool char // On crée le type Booléen
#define TRUE 1
#define FALSE 0

typedef enum { Faux , Vrai } Booleen;  // Fin de la création du type Booléen

typedef struct noeud{
	char lettre;
	struct noeud *PFG,*PFD;
	}*Dictionnaire;

Dictionnaire Creer_Dictionnaire(void);
Dictionnaire Ajouter_Mot(Dictionnaire D, char M[]);
Dictionnaire Supprimer_Mot(Dictionnaire D,char M[]);
Booleen Appartient_Mot(Dictionnaire D,char M[]);
Booleen Dictionnaire_Vide(Dictionnaire D);
