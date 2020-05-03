/* O programa a seguir é uma implementação em C ++ do Rabin Karp
Algoritmo dado no livro CLRS */
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>
#include<ctype.h>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

// constD é o número de caracteres no alfabeto de entrada
#define constDascii 256

/* pat -> pattern
    txt -> text
*/
void search(char palavraDesej[], char txt[], int numPrimo)
{
    palavraDesej = strlwr(palavraDesej);
    txt = strlwr(txt);
    int M = strlen(palavraDesej);
    int N = strlen(txt);
    int i, j;
    int hashPadrao = 0; //hash padrão começa com zero
    int hashTexto = 0; // valor do hash para txt inicia em zero
    int h = 1;


    // O valor de h seria "pow (d, M-1)% q"// The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * constDascii) % numPrimo;


    // Calcule o valor de hash do padrão e primeiro// Calculate the hash value of pattern and first
    // janela do texto// window of text
    for (i = 0; i < M; i++)
    {
        hashPadrao = (constDascii * hashPadrao + palavraDesej[i]) % numPrimo;
        hashTexto = (constDascii * hashTexto + txt[i]) % numPrimo;
    }


    // Deslize o padrão sobre o texto, um por um  // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {


        // Verifique os valores de hash da janela atual do texto// Check the hash values of current window of text
        // e padrão. Se os valores de hash corresponderem, apenas // and pattern. If the hash values match then only
        // verifica os caracteres em um // check for characters on by one
        if ( hashPadrao == hashTexto )
        {

            // * Verifique os caracteres um por um * //* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != palavraDesej[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                printf("padrao encontrado no indice %d\n", i);

        }

        // Calcular o valor do hash para a próxima janela de texto: Remover
        // dígito inicial, adicione o dígito final
        if ( i < N-M )
        {
            hashTexto = (constDascii*(hashTexto - txt[i]*h) + txt[i+M])%numPrimo;

            // Podemos obter um valor negativo de t, convertendo-o para positivo

            if (hashTexto < 0)
                hashTexto = (hashTexto + numPrimo);
        }
    }

}

/* Driver code */


int main()
{
    char palavraDesej[100];
    char txt[100000];
    char nomeArquivo[50];

    int numPrimo = 101; // A prime number

//===================================================//////////////////////////////////=================================



    printf("\n");
    printf("================ Estrutura de dados Busca-em-Strings Metodo Rabin Karp ========================");
    printf("\n\n\n");


//==================================================//////////////////////////////////===================================
printf("informe o caminho, nome e extensao do arquivo para que o sistema faca a busca");
    printf("\n\n");
    scanf("%s", nomeArquivo);

    printf("Para que seja feita a busca, informe a palavra ou frase desejada");
    printf("\n\n");
    scanf("%s", palavraDesej);

    // MANIPULAÇÂO DE ARQUIVO

     FILE *arquivo;

    arquivo = fopen(nomeArquivo,"rt");//wt = gravação, rt = leitura, a = append
    if(arquivo == NULL)
    {
        printf("Não foi possivel abrir o arquivo");
        exit (0);
    }

 //   fgets(txt, 100000, arquivo);

     while(fgets(txt, sizeof(txt), arquivo) != NULL)
    //while(fgets(txt,100000,arquivo)!= NULL);

    printf("\n\n\n");

    printf("\n\n\n");

    printf("\n\n\n");

    search(palavraDesej, txt, numPrimo);

    printf("\n\n\n");
    printf("texto completo>>\n%s",txt);


    printf("\n\n\n");
    system("pause");

    return 0;
}
