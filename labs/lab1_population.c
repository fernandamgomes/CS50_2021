#include <stdio.h>

// Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
// Your program should print the number of years required for the llama population to reach the end size

int main(void)
{

    // Prompt for start size
    int startsize;
    do
    {
        printf("Start size:");
        scanf("%d", &startsize);
    }
    while (startsize < 9);

    // Prompt for end size
    int endsize;
    do
    {
        printf("End size:");
        scanf("%d", &endsize);
    }   
    while (endsize < startsize);
    
    // Calculate number of years until we reach threshold
    int years = 0;
    
    if (startsize == endsize)
    { 
        years = 0;
    }
    else
    {
        do
        {
            startsize = startsize + startsize / 3 - startsize / 4;
            years = years + 1;
        }
        while (startsize < endsize);
    }

    // Print number of years
    printf("Years: %d\n", years);
}
