#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct entreeCSV //structure qui permet de stocker les différentes valeurs d'une entree dans le fichier csv
{
    char *lon;
    char *lat;
    char *nombre;
    char *adresse;
    char *ville;
    char *codePostal;
    char *hash;
} entreeCSV;

int menuGenerateur(int limite, char **tab)
{
    int choix = -1;

    for(int i = 0 ; i < limite ; i++)
    {
        printf("\n%s",tab[i]);
    }

    while (choix > limite || choix < 1)
    {
        printf("\nQue voulez-vous faire ? ");
        scanf("%d", &choix);
    }
    
    return choix;
}

//code donné dans l'ennoncé
char *strsep (char **stringp, const char *delim)
{
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


int plusPetit(entreeCSV *t, int taille, int i)
{
    int petit = 0;
    for (i ; i < taille ; i++)
    {
        if (strcmp(t[petit].codePostal, t[i].codePostal))
        {
            petit = i;
        }
    }

    return petit;
}

entreeCSV *triBreton(entreeCSV *t, int taille, int interval, FILE *fic)
{
    clock_t start = clock();
    clock_t end;
    entreeCSV *copieTab = t;
    for (int i = 0 ; i < taille; i++)
    {
        t[i] = copieTab[plusPetit(copieTab, taille, i)];
        if (i % interval == 0)
        {
            end = clock();
            fprintf(fic, "%d;%d\n", i, ((end - start) * 1000 / CLOCKS_PER_SEC));
        }
        
    }
    
    return t;
}

int main()
{
    int run = 1;
    int limitesEntree = 0;
    int i = 0;
    int interval = 0;
    entreeCSV *stockage = NULL;
    entreeCSV *tabCopie = NULL;

    char entree[1024];
    char *jeton;
    const char separateurs[] = ":,;"; 

    char *menuChoixUn[] = {"1. Afficher", "2. Tri", "3. Quitter\n"};
    int choix = -1;

    FILE *fichier = fopen("../ressources/baseDeDonnee/france2.csv", "r"); // creer un pointeur fichier contenant un flux (ici un fichier)
    FILE *classeur = fopen("../ressources/temps.csv", "w"); // creer un pointeur classeur pointant vers un flux (ici un fichier)
    fprintf(classeur, "NombreLigne;Temps\n"); //premiere ligne du fichier temps.csv

    if(fichier == NULL)
    {
        exit(1); //si impossible de lire le fichier le programme s'arrête et renvoie l'erreur "1"
    }

    printf("Combien de lignes : ");
    scanf("%d", &limitesEntree);
    printf("\nInterval entre chaque releve de temps : ");
    scanf("%d", &interval);

    int taille = limitesEntree;
    int dureeTotale = 0;

    stockage = malloc(limitesEntree * sizeof(entreeCSV));
    tabCopie = stockage;

    clock_t debutChrono = clock();
    clock_t finChrono;
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
        if (i % interval == 0) //tous les "interval" nombres
        {
            finChrono = clock();
            fprintf(classeur, "%d;%d\n", i, ((finChrono - debutChrono) * 1000 / CLOCKS_PER_SEC));
        }
    }
    if (i % interval != 0) // relever le temps de la derniere ligne lue (par exemple je veux lire 10 lignes et releve le temps toutes les 4 entree, le programme relevera quand même le temps de l'ouverture de la derniere ligne)
    {
        finChrono = clock();
        fprintf(classeur, "%d;%d\n", i, ((finChrono - debutChrono) * 1000 / CLOCKS_PER_SEC));
        dureeTotale = (finChrono - debutChrono) * 1000 / CLOCKS_PER_SEC;
        printf("\nDuree totale de la lecture : %d ms", dureeTotale);
    }

    fclose(fichier);

    while(run)
    {
        choix = menuGenerateur(3, menuChoixUn);
    char *menuChoixDeux[] = {"1. Tri Breton"};

        if(choix == 1)
        {
            for(int i = 0 ; i < taille ; i++)
            {
                printf("\nentree numero : %d\ncoordonnees : %s, %s\nadresse : %s %s a %s, %s\n",i + 1, stockage[i].lon, stockage[i].lat, stockage[i].nombre, stockage[i].adresse, stockage[i].ville, stockage[i].codePostal);
            }
        }

        else if (choix == 2)
        {
            choix = menuGenerateur(1, menuChoixDeux);
            debutChrono = clock();
            if (choix == 1)
            {
                triBreton(stockage, taille, interval, classeur);
            }

            finChrono = clock();
        }

        else
        {
            run = 0;
        }
        
    }


    fclose(classeur);
    free(stockage);

    return 0;
}

