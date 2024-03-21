#ifndef ANALYSEUR_H
#define ANALYSEUR_H

#include <stdio.h>
#include <stdlib.h>

// Fonction qui permet l'ouverture du fichier text
FILE *amorcer(char *fichier);
// Fonction qui permet de lire un caractere du fichier.(regarde la fonction .c pour mieux comprendre)
void lire_caractere();

typedef struct s_balise{
    enum_balise balise; 
    char* signification;  
}t_balise; 

typedef enum {texte_enrichi, document, annexes, contenu, section, titre, liste, item, liste_texte, texte_liste, texte, mot_enrichi, mot_important}enum_balise; 

char* signification_balises[13]; // 13 elments = les 13 balises

// premet de consommer un caractere (regatde le .C)
void consommer(char symbole);
int detection_espace (char c); 
int verif_balise (char c);
char* contenu_balise(char* mot);
void lire_fichier ();




#endif