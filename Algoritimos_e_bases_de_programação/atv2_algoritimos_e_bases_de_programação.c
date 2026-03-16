#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char jog[10];   // Vetor que representa o tabuleiro, as posições de 1 a 9 são as casas do tabuleiro
char sim = 'X'; // Variavel que controla qual simbolo está sendo jogado, será usado para alternar entre "O" e "x".
int nj = 0;     //  nj é o número de jogadas realizadas na partida
int p;          // é a posição escolhida pelo jogador
char vencedor;  //  Variavel que armazena o símbolo do jogador que venceu quando a vitória é identificada

void inicializar() // inicializa o tabuleiro com os números de 1 a 9, para servir de guia visual
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

void tela() // exibe o tabuleiro atual do jogo, a função organiza as posições do vetor em linhas e colunas simulando o jogo de papel
{
    printf(" %c | %c | %c \n", jog[1], jog[2], jog[3]);
    printf("-------------\n");
    printf(" %c | %c | %c \n", jog[4], jog[5], jog[6]);
    printf("-------------\n");
    printf(" %c | %c | %c \n\n", jog[7], jog[8], jog[9]);
}

char simbolo() // Altera o símbolo entre X e O para ser usado por quem está na vez
{
    if (sim == 'X') // se o simbolo atual for X, quando a função é chamada ele muda para O
    {
        sim = 'O';
    }
    else // caso contrário, muda para X
    {
        sim = 'X';
    }
    return sim; // a função retorna o símbolo que será colocado na posição escolhida
}

int verificar_jogada(int pos) // verifica se a jogada é válida, usa 'pos' como parametro para saber a jogada escolhida pelo jogador
{
    if (pos < 1 || pos > 9) // se não estiver no intervalo do tabuleiro, é jogada inválida
    {
        return 0; // jogada inválida
    }

    if (jog[pos] == 'X' || jog[pos] == 'O') // se a posição já está ocupada, é jogada invalida. Verificada com operador OR
    {
        return 0; // jogada inválida
    }
    return 1; // Qualquer outro caso,  jogada válida
}

int triunfo() // Verifica se algum jogador ganhou a partida, comparando se existem 3 símbolos alinhados em coluna, linha, ou diagonal. Usando operador AND
{
    if (jog[1] == jog[2] && jog[2] == jog[3])
        return 1; // linha 1
    else if (jog[4] == jog[5] && jog[5] == jog[6])
        return 1; // linha 2
    else if (jog[7] == jog[8] && jog[8] == jog[9])
        return 1; // linha 3

    else if (jog[1] == jog[4] && jog[4] == jog[7])
        return 1; // coluna 1
    else if (jog[2] == jog[5] && jog[5] == jog[8])
        return 1; // coluna 2
    else if (jog[3] == jog[6] && jog[6] == jog[9])
        return 1; // coluna 3

    else if (jog[1] == jog[5] && jog[5] == jog[9])
        return 1; // diagonal
    else if (jog[3] == jog[5] && jog[5] == jog[7])
        return 1; // diagonal

    return 0;
}

int main() // Inicializa a função principal, que controla a execução do jogo
{
    setlocale(LC_ALL, ""); // uso de caracteres especiais
    inicializar();         // Inicializa o tabuleiro e permite o jogo acontecer enquanto o número de jogadas for menor que 9

    do
    {
        system("clear");                       // Limpa o terminal
        tela();                                // Mostra o tabuleiro atualizado
        printf("Escolha a posição a jogar: "); // Solicita entrada do usuário
        scanf("%d", &p);                       // Armazena a jogada na variável p

        if (verificar_jogada(p)) // Veriica se a jogada é válida
        {
            jog[p] = simbolo(); // Insere o símbolo do jogador na posição escolhida
            nj++;               // Incrementa o número de jogadas total

            if (nj >= 5) // A partir da quinta jogada passa também a verificar se a vitória aconteceu por parte de algum jogador
            {
                if (triunfo()) // Como o símboloa foi alternado antes pela função símbolo(), precisamos descobrir quem foi o jogador que fez a ultima jogada
                {
                    if (sim == 'X') // se foi X, o vencedor é O
                    {
                        vencedor = 'O'; // Altera a  variável para o vencedor correto
                    }
                    else // se foi O,  o  vencedor é X
                    {
                        vencedor = 'X'; // Altera a  variável para o vencedor correto
                    }

                    printf("Parabéns! O jogador "
                           "%c"
                           " venceu a partida!\n",
                           vencedor); // exibe a mensagem de vitória
                    break;            // Encerra o jogo
                }
            }
        }

        else // Caso a posição já esteja ocupada, ou seja inválida por outro motivo

        {
            printf("Essa posição já está ocupada\n");
            printf("Pressione enter para continuar...");
            getchar(); // consome o ENTER anterior do scanf
            getchar(); // espera o usuário apertar ENTER
        }

        system("clear"); // limpa o terminal antes da próxima jogada
        tela();          // mostra o tabuleiro novamente
    } while (nj < 9);

    return 0;
}