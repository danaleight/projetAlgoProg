#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "lecture.h"

//code donné dans l'ennoncé
char *strsep (char **stringp, const char *delim){
    char *begin, *end;
    begin = *stringp;
    if (begin == NULL) return NULL;
        end = begin + strcspn (begin, delim);
    if (end)
    {
        *end++ = '\0';
        *stringp = end;
    } 
    else {stringp = NULL;}
        return begin;
    }

void lectureFichierCSV()
{
    int limitesEntree = 0;
    int i = 0;
    entreeCSV *stockage = NULL;
    char entree[1024];
    char *jeton, *reste;
    const char separateurs[] = ":,;";

    FILE *fichier = fopen("../ressources/baseDeDonnee/france.csv", "r"); // creer un pointeur fichier contenant un flux (ici un fichier)

    if(fichier == NULL)
    {
        exit(1); //si impossible de lire le fichier le programme s'arrête et renvoie l'erreur "1"
    }

    printf("Combien de lignes : ");
    scanf("%d", &limitesEntree);

    stockage = malloc(limitesEntree * sizeof(entreeCSV));
    clock_t debutChrono = clock();
    while(fgets(entree, 1023, fichier) != NULL && limitesEntree> 0) //tant que la fonction n'a pas atteind la fin du fichier ou tant que on a pas atteind la limite de lecture
    {
        char *ligne = strdup(entree);
        //format du fichier csv pour evite d'avoir a le lire a chaque fois : 4.9356384,46.1290477,5098,lotissement vers le plat,,L'Abergement-Clémenciat,,,01400,,5f1f6c0bdb5c901c

       stockage[i].lon = strsep(&ligne,",");
        stockage[i].lat = strsep(&ligne,",");
        stockage[i].nombre = strsep(&ligne,",");
        stockage[i].adresse = strsep(&ligne,",");
        jeton = strsep(&ligne,",");
        stockage[i].ville = strsep(&ligne,",");
        jeton = strsep(&ligne,",");
        jeton = strsep(&ligne,",");
        stockage[i].codePostal = strsep(&ligne,",");
        jeton = strsep(&ligne,",");
        stockage[i].hash = strsep(&ligne,",");

        printf("\nentree numero : %d\ncoordonnees : %s, %s\nadresse : %s %s a %s, %s\n",i + 1, stockage[i].lon, stockage[i].lat, stockage[i].nombre, stockage[i].adresse, stockage[i].ville, stockage[i].codePostal);
    
        limitesEntree--;
        i++;
    }
    clock_t finChrono = clock();
    int dureeTotale = (finChrono - debutChrono) * 1000 / CLOCKS_PER_SEC;
    printf("\nDuree totale de la lecture : %d ms", dureeTotale);

    fclose(fichier);
    free(stockage);
}

//, stockage[i].adresse, stockage[i].ville, &stockage[i].codePostal
//, stockage[i].adresse, stockage[i].ville, stockage[i].codePostal

//!feof(fichier)

//[longitude %s]\n[latitude %s]\n[nombre %s]\n[rue %s]\n[ville %s]\n
//, stockage[i].lon, stockage[i].lat, stockage[i].nombre, stockage[i].adresse, stockage[i].ville

//j'ai essayé cette methode, je pense avoir tout suivie mais j'ai une erreur de type de pointeur

        /*
        stockage[i].lon = strtok(entree, separateurs);
        stockage[i].lat = strtok(NULL, separateurs);
        stockage[i].nombre = strtok(NULL, separateurs);
        stockage[i].adresse = strtok(NULL, separateurs);
        stockage[i].ville  = strtok(NULL, separateurs);
        stockage[i].codePostal = strtok(NULL, separateurs);       
        */// Ce bout de code permet de séparer la chaine de caractere en plusieurs morceau des que les caractères compris dans la variable separateur sont rencontrés, seulement le fichier france.csv etant mal rempli (manque la rue par exemple) cette methode ne fonctionne pas
        //je suis donc dans l'obligation d'utiliser les fonctions suivante :
        
        /*stockage[i].lon = strsep(&entree, separateurs);
        stockage[i].lat = strsep(&entree, separateurs);
        stockage[i].nombre = strsep(&entree, separateurs);
        stockage[i].adresse = strsep(&entree, separateurs);
        strsep(&entree, separateurs);
        stockage[i].ville =  strsep(&entree, separateurs);
        strsep(&entree, separateurs);
        strsep(&entree, separateurs);
        stockage[i].codePostal = strsep(&entree, separateurs);
        */