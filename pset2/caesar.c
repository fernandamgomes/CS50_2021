#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// program that encrypts messages using Caesar’s cipher

int main(int argc, string argv[])
{
    //VARIÁVEIS
    int k;
    int i;
    bool teste = true;
    string input;

    //validating the key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (i = 0; i < strlen(argv [1]); i = i + 1)
        if (isdigit(argv[1][i]))
        {
            teste = true;
        }
        else
        {
            teste = false;
        }

    if (teste == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //encipher text
    if (teste == true)
    {
        k = atoi(argv[1]);
        input = get_string("Plaintext: ");

        printf("Ciphertext: ");
        for (i = 0; i < strlen(input); i = i + 1)
        {
            //for upper case letters
            if (isupper(input[i]))
            {
                input[i] = (input[i] - 65 + k) % 26 + 65;
                printf("%c", input[i]);
            }
            //for lower case letters
            else if (islower(input[i]))
            {
                input[i] = (input[i] - 97 + k) % 26 + 97;
                printf("%c", input[i]);
            }
            //numbers, punctuation, etc should remain unchanged
            else
            {
                printf("%c", input[i]);
            }
        }
        printf("\n");
        return 0;
    }
}
