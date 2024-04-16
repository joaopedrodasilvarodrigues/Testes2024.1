#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime(int *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n\n");
}

typedef struct
{
    int dia, mes, ano;
} Data;

void imprimePonteiro(Data *x)
{
    printf("\n%d/%d/%d\n\n", x->dia, x->mes, x->ano);
}

void reguainglesa(int x)
{
    if (x == 0)
    {
        return;
    }
    reguainglesa(x - 1);
    int i = 0;

    for (i = 0; i < x; i++)
    {
        if (i == 0)
        {
            printf(".");
        }
        printf("-");
    }
    printf("\n");
    reguainglesa(x - 1);
}

int main()
{

    /*int *x;
    int tam, i;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &tam);
    srand(time(NULL));

    x = malloc(tam * sizeof(int));
    if (x)
    {
        printf("memória alocada com sucesso\n\n");
        for (i = 0; i < tam; i++)
        {
            *(x + i) = rand() % 100;
        }
        for (i = 0; i < tam; i++)
        {
            printf("%d ", *(x + i));
        }
        printf("\nDigite um novo tamanho para o vetor:");
        scanf("%d", &tam);
        x = realloc(x, tam);
        if (x)
        {
            printf("\n\nMemória realocada com sucesso\n");
            for (i = 0; i < tam; i++)
            {
                *(x + i) = rand() % 100;
            }
            printf("\nObserve abaixo o seu vetor realocado:\n");

            for (i = 0; i < tam; i++)
            {
                printf("%d ", *(x + i));
            }
            printf("\n\n");
        }
        free(x);
    }
    if (x == NULL)
    {
        printf("falha ao tentar alocar espaço na memória\n\n");
    }*/
    int y;
    scanf("%d", &y);
    reguainglesa(y);

    return 0;
}