#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrice(int *aux[]);
void transpose(int *matrice[]);

int main()
{
    int *matrice[4];

    srand(time(NULL));
    // Cria a matriz
    for (int i = 0; i < 4; i++)
    {
        matrice[i] = (int *)malloc(4 * sizeof(int *));
        for (int j = 0; j < 4; j++)
        {
            int value = rand() % 100;
            matrice[i][j] = value;
        }
    }

    printMatrice(matrice);

    printf("\n");
    transpose(matrice);
    printf("\n");
    printMatrice(matrice);

    return 0;
}

// Transposição da matriz.
void transpose(int *matrice[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int aux = matrice[i][j];
            matrice[i][j] = matrice[j][i];
            matrice[j][i] = aux;
        }
    }
}

//imprime a Matriz
void printMatrice(int *aux[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Item %d,%d: %d\n", i, j, aux[i][j]);
        }
    }
}