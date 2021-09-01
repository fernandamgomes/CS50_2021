#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 50

// In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char LETTERS [26];
int compute_score(char word[MAX_LIMIT]);

int main(void)
{
    //criação do alfabeto
    for (int x = 0; x < 26; x = x + 1)
    {
        LETTERS[x] = x + 97;
    }

    // Get input words from both players
    char word1[MAX_LIMIT];
    printf("Player 1:");
    fgets(word1, MAX_LIMIT, stdin);

    char word2[MAX_LIMIT];
    printf("Player 2:");
    fgets(word2, MAX_LIMIT, stdin);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        printf("Score:\nPlayer 1: %i\nPlayer 2: %i\n", score1, score2);
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
        printf("Score:\nPlayer 1: %i\nPlayer 2: %i\n", score1, score2);
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
        printf("Score:\nPlayer 1: %i\nPlayer 2: %i\n", score1, score2);
    }
}

int compute_score(char word[MAX_LIMIT])
{
    // TODO: Compute and return score for string RELACIONAR PALAVRA, LETRA E VALOR; PASSAR DE MAIUSCULA P MINUSCULA

    int soma = 0;
    for (int i = 0; i < strlen(word); i = i + 1)
    {
        if (isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        for (int a = 0; a < 26; a = a + 1)
        {
            if (word[i] == LETTERS[a])
            {
                soma = soma + POINTS[a];
            }
        }

    }
    return soma;
}
