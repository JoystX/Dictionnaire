#include <stdio.h>
#include <stdlib.h>

#define bool char // On crée le type Booléen
#define TRUE 1
#define FALSE 0

typedef enum Booleen Booleen;
enum booleen { False = 0, True = 1};  // Fin de la création du type Booléen

typedef struct noeud{
	char Mot;
	struct noeud *PFG,*PFD;
	}*Dictionnaire;

Dictionnaire Creer_Dictionnaire(void);
Dictionnaire Ajouter_Mot(Dictionaire D, Mot M);
Dictionnaire Supprimer_Mot(Dictionnaire D,Mot M);
Booleen Appartient_Mot(Dictionnaire D,Mot M);
Booleen Dictionnaire_Vide(Dictionnaire D);
