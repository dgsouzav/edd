#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int tab = 0;
    printf("\ndigite a tabuada que deseja ser visualizada \n\t\t\t\n");
    scanf("%i", &tab);

    for(int x = 0; i <= 10; ++x) {
        printf("%ix%i = %i\n", x, tab, tab, x * tab);

    }

    return 0;
}