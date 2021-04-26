#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "lecture.h"

int main()
{
    const char adresse[256] = "../ressources/test.txt";

    lectureFichierCSV(adresse);
    return 0;
}

