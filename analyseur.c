#include <stdio.h>
#include <stdlib.h>

// pointeur qui stock le chemin vers le fichier txt a lire
FILE *mon_fichier;
// instanciation de la variable qui stock le caractere courant lu
char mon_caractere;
char mot[10]; 
int end_of_file = 0; // fonction EOF renvoie zéro si on n'est pas à la find du fichier 
char balise[16] = "";  // la balise max est de 13 caracteres + deux caracteres de '<' et '>' + \0 // 
int indice_lettre_balise = 0;


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

int detection_espace (char c){
    if (c == ' '){
        return 0; 
    }
    else return 1; 
}

int mot_est_balise () {
    if (mon_caractere == '<'){
        return 0; 
    }
    else return 1; 
}

void contenu_balise (int i) {
    balise[i] = mon_caractere;
}

void lire_fichier (){
    while (mon_caractere != EOF){
        if (mon_caractere == '>'){
            indice_lettre_balise = 0;
            printf ("balise -> %s", balise); 
            mon_caractere = fgetc(mon_fichier);   
            continue;
        }
        else {
            lire_caractere();
            if (mot_est_balise()){
                contenu_balise(indice_lettre_balise); 
                indice_lettre_balise++; 
            }
        }
    }
}

char* remplissage_tableau_balises () {
     
}







// // permet de s'assurer que le caractere qu'on lis est juste (est le caractere courant)
// void consommer(char symbole)
// {
//     // si le caractere courant est le caractere qu'on lis...
//     if (mon_caractere == symbole)
//     {
//         // on lis le caractere
//         lire_caractere();
//     }
//     // sinon on affiche le caractere qu'on attendais et le caractere courant
//     else
//     {
//         printf("Caractere attendu %c , Caractere trouve %c \n", symbole, mon_caractere);
//         exit(-2);
//     };
// }