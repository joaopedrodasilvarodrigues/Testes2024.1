#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int cont;
    printf("%d\n", argc - 1);

    for (cont = 1; cont < argc; cont++)
        printf("%s\n", argv[cont]);

    return 0;
}
