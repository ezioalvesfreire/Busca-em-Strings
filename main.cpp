#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

using namespace std;

bool testar(int teste[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(teste[i]==0)
        {
            return false;
        }
    }
    return true;
}


bool existe( char palavra[], char frase[])
{
    int teste[strlen(palavra)];
    int aux;

    if(strlen(palavra) > strlen(frase ) )
    {
        return false;
    }
    if(strcmp(palavra, frase)==0)
    {
        return true;
    }
    for(int i = 0; i <= strlen(frase) - strlen(palavra); i++)
    {
        if(frase[i] == palavra[0])
        {

            for(int k=0; k<strlen(palavra); k++)
                teste[k]=0;

            aux=i;
            for(int j=0; j<strlen(palavra); j++)
            {
                if(palavra[j]== frase[aux])
                {
                    teste[j] = 1;
                    aux++;
                }
            }
            if( testar(teste, strlen(palavra)))
            {
                return true;
            }
        }

    }
    return false;
}
int main()
{
    char palavra[] = "alves";
    char frase[100];

    printf("\n");
    printf("================ Estrutura de dados Busca-em-Strings ========================");
    printf("\n\n\n");



// MANIPULAÇÂO DE ARQUIVO
    FILE *arquivo;

    arquivo = fopen("teste.txt","rt");//wt = gravação, rt = leitura, a = append
    if(arquivo == NULL)
    {
        printf("Não foi possivel abrir o arquivo");
        exit (0);
    }

    fscanf(arquivo,"%s", &frase);
    printf("vem do arquivo txt >>  %s", frase);


    printf("\n\n\n");

    fclose(arquivo);

    ///////////////////////////////////////////////////

    if(existe(palavra, frase))
    {
        printf("\n\n");
        printf("A palavra existe");
    }
    else
    {
        printf("\n\n\n");
        printf("A palavra nao existe");
    }
    printf("\n\n\n");

    printf("\n\n\n");
    system("pause");
    return 0;
}
