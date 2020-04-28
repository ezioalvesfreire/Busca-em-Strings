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

// d é o número de caracteres no alfabeto de entrada
#define d 256

/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; //hash padrão começa com zero // valor padrão do hash //hash value for pattern
    int t = 0; // valor do has para txt inicia em zero // valor de hash para txt// hash value for txt
    int h = 1;


    // O valor de h seria "pow (d, M-1)% q"// The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;


    // Calcule o valor de hash do padrão e primeiro// Calculate the hash value of pattern and first
    // janela do texto// window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }


    // Deslize o padrão sobre o texto, um por um  // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {


        // Verifique os valores de hash da janela atual do texto// Check the hash values of current window of text
        // e padrão. Se os valores de hash corresponderem, apenas // and pattern. If the hash values match then only
        // verifica os caracteres em um // check for characters on by one
        if ( p == t )
        {

            // * Verifique os caracteres um por um * //* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                printf("padrao encontrado no indice %d\n", i);

        }

        // Calcular o valor do hash para a próxima janela de texto: Remover // Calculate hash value for next window of text: Remove
        // dígito inicial, adicione o dígito final// leading digit, add trailing digit
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;

            // Podemos obter um valor negativo de t, convertendo-o para positivo // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }

}

/* Driver code */


int main()
{
    char pat[100];
    char txt[100000];
    strlwr(pat);
    strlwr(txt);
    char nomeArquivo[50];

    int q = 101; // A prime number

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
    scanf("%s", pat);

    // MANIPULAÇÂO DE ARQUIVO

     FILE *arquivo;

    arquivo = fopen(nomeArquivo,"rt");//wt = gravação, rt = leitura, a = append
    if(arquivo == NULL)
    {
        printf("Não foi possivel abrir o arquivo");
        exit (0);
    }

    //fgets(txt, 100000, arquivo);
    while(fgets(txt, 100000, arquivo) != NULL);

    printf("\n\n\n");

    printf("\n\n\n");

    printf("\n\n\n");

    search(pat, txt, q);

    printf("\n\n\n");
    printf("texto completo>>\n%s",txt);

    fclose(arquivo);

    printf("\n\n\n");
    system("pause");

    return 0;
}
