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
{    frase = strlwr(frase);
     palavra = strlwr(palavra);
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

void abreFechaArquivo(char frase[], char nomeArquivo[]){
    FILE *arquivo;

    arquivo = fopen(nomeArquivo,"rt");//wt = gravação, rt = leitura, a = append
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
  //  fgets(frase, 100000, arquivo);
    while(fgets(frase,100000,arquivo)!= NULL);
    printf("texto completo>>\n%s",frase);

    printf("\n\n\n");

    fclose(arquivo);

}

int main()
{
    char palavra[100];
    char frase[100000];
    char nomeArquivo[50];

    printf("\n");
    printf("================ Estrutura de dados Busca-em-Strings ========================");
    printf("\n\n\n");

    printf("informe o caminho, nome e extensao do arquivo para que o sistema faca a busca");
    printf("\n\n");
    scanf("%s", nomeArquivo);

    printf("Para que seja feita a busca, informe a palavra ou frase desejada");
    printf("\n\n");
    scanf("%s", palavra);

    // MANIPULAÇÂO DE ARQUIVO
    abreFechaArquivo(frase , nomeArquivo);
    resposta(palavra, frase);

    printf("\n\n\n");

    printf("\n\n\n");
    system("pause");
    return 0;
}
