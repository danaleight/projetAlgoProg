#ifndef __lecture__H__
#define __lecture__H__

    typedef struct entreeCSV //structure qui permet de stocker les différentes valeurs d'une entree dans le fichier csv
    {
        int lon;
        int lat;
        int nombre;
        char adresse[256];
        char ville[256];
        int codePostal;
    } entreeCSV;

    void lectureFichierCSV();

#endif