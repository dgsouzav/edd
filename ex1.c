#include<stdio.h>

main()

{

float metros,decimetros,centimetros,milimetros;

printf("informe o valor em metros");

scanf("%f",&metros);

decimetros=metros*10;

centimetros=metros*100;

milimetros=metros*1000;

printf("o valor em decimetros eh:%f",decimetros);

printf("o valor em centimetros eh:%f",centimetros);

printf("o valor em milimetros eh:%f",milimetros);

}