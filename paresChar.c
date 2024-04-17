#include <stdio.h>
#include <string.h>

int mcig(char *impares, int zetsu)
{
    int tamanho = strlen(impares);
    int numPar = 0;

    if (impares[zetsu] == '\0')
        return 0;

    else if (zetsu + 2 < tamanho && impares[zetsu] == impares[zetsu + 2])
    {

        return 1 + mcig(impares, zetsu + 1);
    }
    return 0 + mcig(impares, zetsu + 1);
}

int main()
{
    char impares[1000];

    scanf("%s", impares);
    printf("%d", mcig(impares, 0));
}