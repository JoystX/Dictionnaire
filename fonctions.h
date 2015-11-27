#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool char // On crée le type Booléen
#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 30 // Taille max des mots du dico

typedef enum { Faux , Vrai } Booleen;  // Fin de la création du type Booléen

typedef struct noeud{
	char lettre;
	struct noeud *PFG,*PFD; // Premier fils gauche, premier frère droit
	}*Dictionnaire;

char * fin_du_mot(char mot[], int index);
Dictionnaire Creer_Dictionnaire();
Dictionnaire Ajouter_Mot(Dictionnaire D, char M[]);
Dictionnaire Supprimer_Mot(Dictionnaire D,char M[]);
char* Traiter_Dictionnaire(Dictionnaire D,char motActuel[], Booleen enregistrer);
Booleen Appartient_Mot(Dictionnaire D,char M[], char motActuel[]);
Booleen Dictionnaire_Vide(Dictionnaire D);
char * minuscule (char mot[]);
void enregistrer (char  M[]);
void charger (Dictionnaire D);
