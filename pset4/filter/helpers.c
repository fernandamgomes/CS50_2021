#include "helpers.h"
#include <math.h>

// Converter imagem para grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i = i + 1)
    {
        for (int j = 0; j < width; j = j + 1)
        {
            float average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Converter a imagem para sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i = i + 1)
    {
        for (int j = 0; j < width; j = j + 1)
        {
            float sepiared = round(image[i][j].rgbtRed * 0.393 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtBlue * 0.189);
            if (sepiared > 255)
            {
                sepiared = 255;
            }
            float sepiagreen = round(image[i][j].rgbtRed * 0.349 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtBlue * 0.168);
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            float sepiablue = round(image[i][j].rgbtRed * 0.272 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtBlue * 0.131);
            if (sepiablue > 255)
            {
                sepiablue = 255;
            }
            image[i][j].rgbtRed = sepiared;
            image[i][j].rgbtGreen = sepiagreen;
            image[i][j].rgbtBlue = sepiablue;
        }
    }
    return;
}


// Refletir a imagem horizontalmente
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i = i + 1)
    {
        //swap pixels on horizontally opposite sides; só trocar até a metade, se não a imagem vai inverter uma vez e depois inverter dnv e voltar ao normal
        for (int j = 0; j < width / 2; j = j + 1)
        {
            //é necessário criar tmp para conseguir fazer o swap
            RGBTRIPLE tmp = image[i][j];
            //swap pixels
            image[i][j] = image [i][width - (j + 1)];
            image [i][width - (j + 1)] = tmp;
        }
    }
    return;
}


// Borrar a imagem.c
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //variáveis
    int i = 0;
    int j = 0;
    int h = 0;
    int l = 0;
    RGBTRIPLE tmp[height][width];

    //copiar a imagem pixel por pixel
    for (i = 0; i < height; i = i + 1)
    {
        for (j = 0; j < width; j = j + 1)
        {
            tmp[i][j] = image[i][j];
        }
    }

    //cravar um pixel pra fazer a média e alterar
    for (i = 0; i < height; i = i + 1)
    {
        for (j = 0; j < width; j = j + 1)
        {
            //zerar a soma e o contador quando muda de pixel
            int sumred = 0;
            int sumgreen = 0;
            int sumblue = 0;
            int counter = 0;

            //fazer a média dos pixels no entorno
            for (h = - 1; h <= 1; h = h + 1)
            {
                for (l = -1; l <= 1; l = l + 1)
                {
                    if ((i + h < height) && (i + h >= 0) && (j + l >= 0) && (j + l < width))
                    {
                        sumred = sumred + tmp[i + h][j + l].rgbtRed;
                        sumgreen = sumgreen + tmp[i + h][j + l].rgbtGreen;
                        sumblue = sumblue + tmp[i + h][j + l].rgbtBlue;
                        counter = counter + 1;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            //designar valor borrado para o pixel
            image[i][j].rgbtRed = round((float)sumred / (float)counter);
            image[i][j].rgbtGreen = round((float)sumgreen / (float)counter);
            image[i][j].rgbtBlue = round((float)sumblue / (float)counter);
        }
    }
    return;
}
