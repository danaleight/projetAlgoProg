#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    FILE *fic = fopen("../ressources/test.txt", "r");
    int lettre = 0;

    if(fic == NULL)
    {
        exit(1);
    }

    while (1)
    {
             
    }
    

    fclose(fic);
    return 0;
}