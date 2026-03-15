#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char jog[10];
char sim = 'X';
int nj = 0, p;

void inicializar()
{
    jog[1] = '1';
    jog[2] = '2';
    jog[3] = '3';
    jog[4] = '4';
    jog[5] = '5';
    jog[6] = '6';
    jog[7] = '7';
    jog[8] = '8';
    jog[9] = '9';
}

void tela()
{
    printf(" %c | %c | %c \n", jog[1], jog[2], jog[3]);
    printf("-------------\n");
    printf(" %c | %c | %c \n", jog[4], jog[5], jog[6]);
    printf("-------------\n");
    printf(" %c | %c | %c \n\n", jog[7], jog[8], jog[9]);
}

char simbolo()
{
    if (sim == 'X')
    {
        sim = 'O';
    }
    else
    {
        sim = 'X';
    }
    return sim;
}

int verificar_jogada(jog[p]){
    if (jog[p] != )
    {
            
    }
}

void main()
{
    setlocale(LC_ALL, "");
    inicializar();
    do
    {
        system("clear");
        tela();
        printf("Escolha a posição a jogar: ");
        scanf("%d", &p);
        jog[p] = simbolo();
        nj++;
        system("clear");
        tela();
    } while (nj < 9);
}