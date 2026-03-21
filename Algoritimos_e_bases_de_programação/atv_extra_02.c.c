#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

// Declaração dos tipos das variáveis globais. char (Caractere) para: si -> (símbolo do jogador), armpos[10] -> (Vetor responsável pelo armazenamento das posições do tabuleiro), con -> (Responsável pelo armazenamento
// referente à continuidade do jogo). E int (Inteiros) para: po -> (Posição da jogada atual), nj -> (número de jogadas atual), res -> (Variável que controla o resultado do jogo).

char si, armpos[10], con;
int po, nj, res;

// A função inicializar() tem como objetivo configurar o estado inicial do jogo, atribuindo valores padrão às variáveis de controle e preenchendo o vetor que é responsável pelo tabuleiro.
// Inicializa as variaveis: si = "X" (primeiro jogador usará o simbolo "X"), po = 0 (inicializa a variável que armazenará a jogada escolhida, usando 0 por estar fora do range do tabuleiro que vai de 1 a 9)
// nj = 0 (Inicializa a variável responsável por contar o número de jogadas), res = 0 (Responsável por armazenar o resultado da partida), con ='n' (responsável por controlar a continuidade da partida)
// Loop for, responsável por percorrer todos os índices do vetor armpos convertendo o número "x" em um texto (string) com o método -sprintf- e armazenando esse valor na posição x do vetor.
// A função é chamada no início da execução do programa dentro de main(), e também chamada novamente caso os jogadores queiram jogar novamente após o término da partida.
// A função também prepara os dados que serão utilizados pela função tela()

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
// Usando o %c, exibe-se o valor armazenado em cada posição do vetor armpos, podendo assim mostrar o estado atual de cada posição do tabuleiro
// A função é chamada a cada rodada do jogo, antes do jogador escolher uma nova posição
// A função também é chamada quando ocorre vitória ou empate para mostrar o estado final do tabuleiro.
//

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
// com uso da condicional if, verifica o estado atual da variável, e troca o símbolo com base no símbolo atual armazenado, garantindo a alternância entre os jogadores.
// Ao fim, retorna o novo símbolo.
// A função é chamada sempre que uma jogada válida é realizada, antes de armazenar o símbolo na posição escolhida do tabuleiro.
// O valor retornado é usado para preencher o vetor armpos, representando a jogada realizada no tabuleiro.
// A alteração da variável si influencia diretamente o que será exibido pela função tela().
// Ajuda também na verificação de vitória realizada pela função triunfo(), pois os símbolos armazenados em armpos são usados para verificar combinações vencedoras.

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

// A função validarjog tem como objetivo analisar a jogada feita e validar o movimento, caso a jogada seja irregular vai gerar um valor que vai ser lido futuramente e aparecerá uma mensagem relatando o erro.
// A função foi declarada como _Bool pois ela dá um valor verdadeiro ou falso.
// A função começa declarando uma variável e dizendo que o valor dela atribuído é falso, depois há uma estrutura de validação (if), que analisa se naquela posição jogada não há nenhum simbolo (seja o "X", seja o "O").
// Caso algum dos jogadores já tenha escolhido aquela casa, a variável enc retorna como verdadeira e esse valor é lido futuramente.
// Com exceção do void, toda função tem que retornar um valor, e nesse caso é a variável enc, terminando essa estrutura de validação.

_Bool validarjog(int p)
{
    _Bool enc = false;
    if ((armpos[p] == 'X') || (armpos[p] == 'O'))
    {
        enc = true;
    }
    return enc;
}

// A função triunfo tem como objetivo verificar, a partir de um número z de jogadas, se há um vencedor.
// A função é declarada como int visto que ela tem que retornar alguns valores inteiros (nesse caso 0;1;2) que a função vai dar quando for chamada.
// Ela começa dizendo que o valor de r é 0, esse valor indica que ainda não há um vencedor.
// Depois é feita várias funções de condicionais (os if e else if) que vão analisar se existem 3 símbolos iguais seja na mesma linha,coluna ou diagonal, se isso acontecer, a função declara r como 1 indicando para o sistema que há um vencedor.
// Caso nenhuma jogada caracterize um triunfo, e o número de jogadas for igual a 9, a função declara r como 2, que significa que deu empate e o jogo acabou.
// A função termina declarando r como retorno a ser analisado.

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

// A função principal, ela vai reunir todas as outras funções e fazê-las funcionar para o usuário, seja na interface seja na lógica interna.
// A função é declarada como int, e unico valor de retorno é 0,  mas não influencia em nenhuma outra função.
// O setlocale com LC_ALL ajusta a localização (idioma/acentuação) da língua do S.O., no caso, para o português, isso possibilita a leitura do console de alguns acentos no printf.
// Depois é chamada a função inicializar, visto que é ela quem declara algumas variáveis importantes e seus valores iniciais, além de preencher o tabuleiro com a numeração devida.
// É feita a principal estrutura de repetição, o do e while, que vão continuar o jogo ou a ação enquanto o nj for menor que 9 e res for 0.
// Agora é chamada a função tela, numa estrututura de repetição.
// É pedido para o usuário digitar um número com o comando scanf, o valor digitado é lido e a tela não atualiza enquanto o jogador não digitar um número de 1 a 9, tendo em vista que na tela() só aparecem os números inteiros da sequencia dita.
// Esse mesmo valor é lido por uma estrutura condicional a qual tem a mesma condição da estrutura de repetição e, caso seja um valor diferente da sequência estabelecida aparece uma mensagem, o sistema para por 3 segundos (função do sleep) e o jogador pode escolher uma casa possível de ser jogada.
// Caso o valor digitado esteja dentro do espectro, há uma estrutura condicional que analisa o valor da função validarjog(po), caso o valor seja falso, o jogo continua e o nj é somado mais 1.
// Caso contrário aparece uma mensagem de casa já ocupada e a jogada retorna sem atualizar o nj.
// A partir da quinta rodada a variável res é igualada ao retorno da função triunfo() e verifica 3 casos, caso seja 1, já há um vencedor e aparece uma mensagem avisando e perguntando se quer fazer outro jogo.
// Caso seja 2 deu velha, aparece a mensagem e pergunta se quer fazer outro jogo.
// Caso seja 0, o jogo continua e a cada rodada é analisado se há um vencedor.
// Quando o jogador digita s ou n, é analisado e em caso seja s volta toda a função com o novo jogo, caso contrário, apenas encerra o programa e aparece uma mensagem de fim de jogo.

int main()
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
                sleep(3);
                printf("Deseja continuar jogando [s/n]: ");
                scanf(" %c", &con);
            }

            if (tolower(con) == 's')
                inicializar();
        }
    } while ((nj < 9) && (res == 0));
    system("clear");
    printf("Fim de Jogo");

    return 0;
}