#ifndef ANALYSEUR_H
#define ANALYSEUR_H

#include <stdio.h>
#include <stdlib.h>

// Fonction qui permet l'ouverture du fichier text
FILE *amorcer(char *fichier);
// Fonction qui permet de lire un caractere du fichier.(regarde la fonction .c pour mieux comprendre)
void lire_caractere();

void consommer(char symbole);

#endif