#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>
#include<ctype.h>
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
    if(strcasecmp(palavra, frase)==0)
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
void resposta(char palavra[], char frase[])
{
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
}

int main()
{
    char palavra[] = "Cpf";
    char frase[100000];
    strlwr(palavra);

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
    /*
        while (!feof(arquivo))
        {
            fgets(frase, 1000, arquivo);

        }
    */
    fgets(frase, 100000, arquivo);
    printf("vem do arquivo txt >>  %s", frase);
    strlwr(frase);

    printf("\n\n\n");

    fclose(arquivo);

    resposta(palavra, frase);

    printf("\n\n\n");

    printf("\n\n\n");
    system("pause");
    return 0;
}
