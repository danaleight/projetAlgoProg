#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lecture.h"

void lectureFichierCSV()
{
    int limitesEntree = 5;
    int i = 0;
    entreeCSV *stockage = NULL;
    signed char entree[1024];
    char *entreeSeparee = NULL;
    char trash[64];

    FILE *fichier = fopen("../ressources/baseDeDonnee/france.csv", "r"); // creer un pointeur fichier contenant un flux (ici un fichier)

    if(fichier == NULL)
    {
        exit(1); //si impossible de lire le fichier le programme s'arrête et renvoie l'erreur "1"
    }

    stockage = malloc(limitesEntree * sizeof(entreeCSV));
    printf("taille : %d, position : %d\n", sizeof(stockage), &stockage);

    fgets()

    while(!feof(fichier) && limitesEntree> 0) //trouver la condition
    {
        //4.9356384,46.1290477,5098,lotissement vers le plat,,L'Abergement-Clémenciat,,,01400,,5f1f6c0bdb5c901c
        
        limitesEntree--;
        i++;
    }

    fclose(fichier);
}

//, stockage[i].adresse, stockage[i].ville, &stockage[i].codePostal
//, stockage[i].adresse, stockage[i].ville, stockage[i].codePostal