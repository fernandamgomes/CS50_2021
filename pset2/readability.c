#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// program that computes the approximate grade level needed to comprehend some text

int main(void)
{
    //VARIÁVEIS
    int letters = 0;
    int words = 1;
    int sentences = 0;
    float L;
    float S;
    int index;
    
    
    string text = get_string("Text: "); 
    
    //Contar o número de letras
    for (int i = 0; i < strlen(text); i = i + 1)
    {
        if (isalpha(text[i])) 
        {
            letters = letters + 1;
        }
        if ((text[i] == ' ') & (text[i + 1] != ' '))
        {
            words = words + 1;
        }
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences = sentences + 1;
        }
    }
    
    if (text[1] == ' ')
    {
        words = words - 1;
    }
    
    // Coleman-Liau index
    L = 100 * (float)letters / (float)words;
    S = 100 * (float)sentences / (float)words;
    index = round(0.0588 * L - 0.296 * S - 15.8);
    //L is the average number of letters per 100 words
    //S is the average number of sentences per 100 words in the text
    
    //Print reading level
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", index);
    }
}
