#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef enum name
    {
        Jean,
        Robert,
        Simon,
        Edward
    } name;

    typedef struct type_joueur
    {
        int hp;
        int mp;
        int age;
        name nom;
    } joueur;

    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));
    printf("type joueur : %d octets\n", sizeof(joueur));

    return 0;
}
