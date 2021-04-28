#ifndef __lecture__H__
#define __lecture__H__

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

    void lectureFichierCSV();
    char *strsep (char **stringp, const char *delim);

#endif