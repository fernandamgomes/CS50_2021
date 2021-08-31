#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// program that calculates the minimum number of coins required to give a user change
int main(void)
{
    //VARIÁVEIS
    float dolar;
    int soma = 0;


    //PEDIR VALOR DO TROCO
    do
    {
        dolar = get_float("Change:");
    }
    while (dolar < 0);

    int centavos = round(dolar * 100);

    //CALCULAR NÚMERO DE MOEDAS
    while (centavos >= 25)
    {
        soma = soma + 1;
        centavos = centavos - 25;
    }

    while (centavos >= 10)
    {
        soma = soma + 1;
        centavos = centavos - 10;
    }

    while (centavos >= 5)
    {
        soma = soma + 1;
        centavos = centavos - 5;
    }

    while (centavos >= 1)
    {
        soma = soma + 1;
        centavos = centavos - 1;
    }

    //IMPRIMIR NÚMERO DE MOEDAS
    printf("%i\n", soma);
}
