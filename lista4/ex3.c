#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j;
    int mat[5][5];
    srand(time(NULL));
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            mat[i][j] = rand() % 10;
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}