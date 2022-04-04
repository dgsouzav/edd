#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, vogal, cont;

    printf("digite uma frase: ");
    gets(str);

    for(i = 0; i < strlen(str); i++)
    {
        vogal = 0;
        for(j = 0; j < strlen(str); j++)
        {
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            {
                vogal++;
            }
        }
        printf("a vogal %c aparece %d vezes\n", str[i], vogal);
    }

    return 0;
}