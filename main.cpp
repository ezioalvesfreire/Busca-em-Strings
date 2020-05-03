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


bool existe( char stringDesejada[], char textoAux[])
{    textoAux = strlwr(textoAux);
     stringDesejada = strlwr(stringDesejada);
    int teste[strlen(stringDesejada)];
    int aux;

    if(strlen(stringDesejada) > strlen(textoAux ) )
    {
        return false;
    }
    if(strcasecmp(stringDesejada, textoAux)==0)
    {
        return true;
    }
    for(int i = 0; i <= strlen(textoAux) - strlen(stringDesejada); i++)
    {
        if(textoAux[i] == stringDesejada[0])
        {

            for(int k=0; k<strlen(stringDesejada); k++)
                teste[k]=0;

            aux=i;
            for(int j=0; j<strlen(stringDesejada); j++)
            {
                if(stringDesejada[j]== textoAux[aux])
                {
                    teste[j] = 1;
                    aux++;
                }
            }
            if( testar(teste, strlen(stringDesejada)))
            {
                return true;
            }
        }

    }
    return false;
}
void resposta(char stringDesejada[], char textoAux[])
{
    if(existe(stringDesejada, textoAux))
    {
        printf("\n\n");
        printf("A Srting foi encontrada!");
    }
    else
    {
        printf("\n\n\n");
        printf("Nao foi possivel encontrar a string desejada!");
    }
}

void abreFechaArquivo(char arquivoTexto[], char nomeArquivo[], char textoAux[]){
    FILE *arquivo;

    arquivo = fopen(nomeArquivo,"rt");//wt = gravação, rt = leitura, a = append
    if(arquivo == NULL)
    {
        printf("Não foi possivel abrir o arquivo");
        exit (0);
    }

        while (!feof(arquivo))
        {
            fgets(arquivoTexto, 300000, arquivo);
            strcat(textoAux,arquivoTexto);

        }

    printf("texto completo>>\n%s",textoAux);

    printf("\n\n\n");

    fclose(arquivo);

}

int main()
{
    char stringDesejada[100];
    char arquivoTexto[300000];
    char nomeArquivo[50];
    char textoAux[300000];

    printf("\n");
    printf("================ Estrutura de dados Busca-em-Strings Metodo NAIVE ========================");
    printf("\n\n\n");

    printf("Informe o caminho, nome e extensao do arquivo para que o sistema faca a busca");
    printf("\n\n");
    scanf("%s", nomeArquivo);

    printf("Informe a palavra ou frase desejada para busca");
    printf("\n\n");
    scanf("%s", stringDesejada);

    // MANIPULAÇÂO DE ARQUIVO
    abreFechaArquivo(arquivoTexto , nomeArquivo, textoAux);

    printf("AGUARDE...\n");
    printf("A BUSCA ESTA SENDO FEITA!");
    printf("\n\n");
    resposta(stringDesejada, textoAux);

    printf("\n\n\n");

    printf("\n\n\n");
    system("pause");
    return 0;
}
