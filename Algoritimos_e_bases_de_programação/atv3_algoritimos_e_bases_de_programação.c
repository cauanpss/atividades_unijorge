#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

// Declaração dos tipos das variáveis globais. char (Caractere) para: si -> (símbolo do jogador), armpos[10] -> (Vetor responsável pelo armazenamento das posições do tabuleiro), con -> (Responsável pelo armazenamento
// referente a continuidade do jogo). E int (Inteiros) para: po -> (Posição da jogada atual), nj -> (número de jogadas atual), res -> (Variável que contorla o resultado do jogo).

char si, armpos[10], con;
int po, nj, res;

// A função inicializar() tem como objetivo configurar o estado inicial do jogo, atribuindo valores padrão as variáveis de controle e preenchendo o vetor que ée responsável pelo tabuleiro.
// Inicializa as variaveis: si = "X" (primeiro jogador usara o simbolo "X"), po = 0 (inicializa a variável que armazenara a jogada escolhida, usando 0 por estar fora do range do tabuleiro que vai de 1 a 9)
// nj = 0 (Inicializa a variável responsável por contar o número de jogadas), res = 0 (Responsável por armazenar o resultado da partida), con ='n' (responsável por controlar a continuidade da partida)
// Loop for, responsável por percorrer todos os índices do vetor armpos convertendo o número "x" em um texto (string) com o método -sprintf- e armazenando esse valor na posição x do vetor.


void inicializar()
{
    si = 'X';
    po = 0;
    nj = 0;
    res = 0;
    con = 'n';
    for (int x = 1; x < 10; x++)
    {
        sprintf(&armpos[x], "%d", x);
    }
}

// A função tela() tem como objetivo exibir o estado atual do "tabuleiro" do jogo num console limpo de informações.
// Usando system("clear") a função "limpa" a tela do terminal/console, 
// Utilizando algumas chamadas de printf, forma as três linhas do tabuleiro.
// usando o %c exibe  o valor armazenado em cada posição do vetor armpos, podendo assim mostrar o estado atual de cada posição do tabuleiro

void tela()
{
    system("clear");
    printf("  %c | %c | %c\n", armpos[1], armpos[2], armpos[3]);
    printf(" ------------\n");
    printf("  %c | %c | %c\n", armpos[4], armpos[5], armpos[6]);
    printf(" ------------\n");
    printf("  %c | %c | %c\n\n", armpos[7], armpos[8], armpos[9]);
}

// A função simbolo() tem como objetivo controlar/alternar o estado atual do símbolo armazenado em si.
// com uso da condicional if, verifica o estado atual da variável, e troca o símbolo com base no símbolo atual armazenado, garantindo a alternancia entre os jogadores.
// Ao fim, retorna o novo símbolo.

char simbolo()
{
    if (si == 'X')
    {
        si = 'O';
    }
    else
    {
        si = 'X';
    }
    return si;
}

_Bool validarjog(int p)
{
    _Bool enc = false;
    if ((armpos[p] == 'X') || (armpos[p] == 'O'))
    {
        enc = true;
    }
    return enc;
}

int triunfo()
{
    int r = 0;
    if ((armpos[1] == armpos[2]) && (armpos[2] == armpos[3]))
    {
        r = 1;
    }
    else if ((armpos[4] == armpos[5]) && (armpos[5] == armpos[6]))
    {
        r = 1;
    }
    else if ((armpos[7] == armpos[8]) && (armpos[8] == armpos[9]))
    {
        r = 1;
    }
    else if ((armpos[1] == armpos[4]) && (armpos[4] == armpos[7]))
    {
        r = 1;
    }
    else if ((armpos[2] == armpos[5]) && (armpos[5] == armpos[8]))
    {
        r = 1;
    }
    else if ((armpos[3] == armpos[6]) && (armpos[6] == armpos[9]))
    {
        r = 1;
    }
    else if ((armpos[3] == armpos[5]) && (armpos[5] == armpos[7]))
    {
        r = 1;
    }
    else if ((armpos[1] == armpos[5]) && (armpos[5] == armpos[9]))
    {
        r = 1;
    }
    else if (nj == 9)
    {
        r = 2;
    }
    return r;
}

void main()
{
    setlocale(LC_ALL, "");
    inicializar();
    do
    {
        do
        {
            tela();
            printf("Digite a posição desejada: ");
            scanf("%d", &po);
            if ((po < 1) || (po > 9))
            {
                printf("Posição inválida!\n");
                sleep(3);
            }
        } while ((po < 1) || (po > 9));
        if (validarjog(po) == false)
        {
            armpos[po] = simbolo();
            nj++;
        }
        else
        {
            printf("Posição já utilizada\n");
            sleep(3);
        }
        if (nj >= 5)
        {
            res = triunfo();
            if (res == 1)
            {
                tela();
                printf("Parabéns %c, você venceu!\n", armpos[po]);
                sleep(3);
                printf("Deseja continuar jogando [s/n]: ");
                scanf(" %c", &con);
            }
            else if (res == 2)
            {
                tela();
                printf("Deu velha!\n");
                sleep(3);""
                printf("Deseja continuar jogando [s/n]: ");
                scanf(" %c", &con);
            }

            if (tolower(con) == 's')
                inicializar();
        }
    } while ((nj < 9) && (res == 0));
    system("clear");
    printf("Fim de Jogo");
}