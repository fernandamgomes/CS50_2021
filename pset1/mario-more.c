#include <cs50.h>
#include <stdio.h>

// Generates Super Mario style pyramid

int main(void)
{
    //VARIÁVEIS
    int altura;
    int coluna;
    int linha;

    //Pedir input
    do
    {
        altura = get_int("Qual a altura da pirâmide? ");
    }
    while (altura < 1 || altura > 8);

    for (coluna = 0; coluna < altura; coluna = coluna + 1)
    {
        // o que esta na linha
        for (linha = altura - 1; linha > coluna; linha = linha - 1)
        {
            printf(" ");
        }
        for (linha = - 1; linha < coluna; linha = linha + 1)
        {
            printf("#");
        }
            
        for (linha = 0; linha < 2; linha = linha + 1)
        {
            printf(" ");
        }
                
        for (linha = - 1; linha < coluna; linha = linha + 1)
        {
            printf("#");
        }
                    
        printf("\n");
        // fim de cada linha
    }
}
