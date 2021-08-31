#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// program that implements a substitution cipher

int main(int argc, string argv[])
{
    //VARIÁVEIS
    bool teste = true; 
    string plaintext; 
    int i;
    int x; 
    int cipher = 0; 
    
    //única command line 
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n"); 
        return 1;
    }
    
    for (i = 0; i < strlen(argv[1]); i = i + 1)
    {
        if (isalpha(argv[1][i]))
        {
            teste = true;
        }
        //Não aceitar caracteres fora do alfabeto 
        else
        {
            teste = false;
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
        //barrar repetição de caracteres
        for (x = 0; x < strlen(argv[1]); x = x + 1)
        {
            if ((argv[1][i] == argv[1][x]) && (i != x))
            {
                printf("Characters can't be repeated\n"); 
                return 1; 
            }
        }
    }
    
    //não aceitar uma substitution key com mais ou menos de 26 caracteres (alfabeto)
    if (i != 26)
    {
        printf("Key must contain 26 characters.\n"); 
        return 1;
    }
    
    //transformar o plaintext em ciphertext 
    if (teste == true)
    {
        plaintext = get_string("plaintext: "); 
        printf("ciphertext: "); 
        
        for (i = 0; i < strlen(plaintext); i = i + 1)
        {
            //para minúsculas
            if (islower(plaintext[i]))
            {
                //Relacionar letras do alfabeto x ciphertext
                cipher = plaintext[i] - 'a';
                cipher = tolower(argv[1][cipher]); 
                printf("%c", cipher);
            }
            
            //para maiúsculas
            else if (isupper(plaintext[i]))
            {
                //Relacionar letras do alfabeto x ciphertext
                cipher = plaintext[i] - 'A';
                cipher = toupper(argv[1][cipher]); 
                printf("%c", cipher);
            }
            
            //para caracteres fora do alfabeto, desconsiderar
            else 
            {
                printf("%c", plaintext[i]);
            }
            //fim do texto 
        }
        printf("\n");
        return 0; 
    }
    
}
