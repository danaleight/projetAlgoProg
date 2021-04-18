#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    FILE *fic = fopen("../ressources/test.txt", "r");
    int lettre = 0;
    int id = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    int ligneRestante = 2;

    if(fic == NULL)
    {
        exit(1);
    }

    while (ligneRestante > 0)
    {
        fscanf(fic, "%d,%d,%d,%d,%d", &id, &num1, &num2, &num3, &num4);
        printf("id : %d, %d | %d | %d | %d\n", id, num1, num2, num3, num4);
        ligneRestante--;
    }
    

    fclose(fic);
    return 0;
}