#include <stdlib.h>
#include <stdio.h>
#include "lecture.h"

void lectureFichierCSV(char adresse)
{
    printf("efuie");

    FILE *fic = fopen(adresse, "r");
    

    if(fic == NULL)
    {
        exit(1); //si impossible de lire le fichier le programme s'arrête et renvoie l'erreur "1"
    }

    while(1) //trouver la condition
    {
        fscanf(fic, "%d,%d,%d", &donnee1, &donnee2, &donnee3); //mettre le formatage du fichier ici : "donnée1SéparateurDonnée2....", &variableDonnée1, &variableDonnée2
        printf("id : %d | %d | %d\n", donnee1, donnee2, donnee3);
    }

    fclose(fic);
}