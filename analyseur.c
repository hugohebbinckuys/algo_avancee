#include <stdio.h>
#include <stdlib.h>

// pointeur qui stock le chemin vers le fichier txt a lire
FILE *mon_fichier;
// instanciation de la variable qui stock le caractere courant lu
char mon_caractere;

void amorcer(char *filename)
{
    // ouverture du fichier en fonction de sont chemin
    mon_fichier = fopen(filename, "r");
    // si le fichier n'est pas trouvée renvoie une erreur
    if (mon_fichier == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier \n");
    }
}

void lire_caractere()
{
    // stock le caractere  dans mon_caractere qui est lu grace a fgetc a qui on passe en parametre le fichier.
    // fgetc mémorise le derniers caractere lu , afin de donnée le prochain caractere automatiquement.
    mon_caractere = fgetc(mon_fichier);
    // affiche le caractere courant lu.
    printf("%c", mon_caractere);
}

void consommer(char symbole)
{
    if (mon_caractere == symbole)
    {
        lire_caractere();
    }
    else
    {
        printf("Caractere attendu %c , Caractere trouvée %c \n", symbole, mon_caractere);
        exit(-2);
    }
}