#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main() {
    setlocale(LC_ALL, "");
    
    int i, valor = 0;
    
    char pla[15], inv[15];

    printf("\ndigite uma palavra: ");
    gets(pla);

    for(i = 0; pla[i]; i++){
    pla[i] = tolower(pla[i]);
    }

    strcpy(inv, pla);

    strrev(inv);

    valor = strcmp(pla, inv);

    if (valor == 0)
        printf("\na palavra %s é palíndroma\n", pla);
    else
        printf("\na palavra %s não é palíndroma\n", pla);

    return 0;
}