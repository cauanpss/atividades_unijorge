// Principais códigos ANSI:

// \033[0m → reset
// \033[1;31m → vermelho
// \033[1;32m → verde
// \033[1;3/3m → amarelo
// \033[1;34m → azul
// \033[1;35m → roxo
// \033[1;36m → ciano

#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, scanf)
#include <stdlib.h>  // Biblioteca para funções do sistema (system)
#include <locale.h>  // Biblioteca para configuração de idioma (setlocale)
#include <unistd.h>  // Biblioteca para controle de tempo (sleep)
#include <ctype.h>   // Biblioteca para manipulação de caracteres (tolower)
#include <stdbool.h> // Biblioteca que permite o uso de booleanos (true/false)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Variáveis globais utilizadas no sistema.
// op -> armazena a opção escolhida pelo usuário no menu.
// num -> armazena o número digitado para operações como consulta, alteração ou exclusão.
// idc -> guarda a posição onde um número foi encontrado na função consultar.
// idg -> indica a quantidade de elementos cadastrados na lista.
// lista[5] -> vetor que armazena os números digitados pelo usuário (máximo de 5).

int op, num, idc, idg, lista[5];

// A função inicializar() é responsável por deixar o sistema pronto para uso.
//  Nela, todas as variáveis globais recebem seus valores iniciais.
//  A variável op é definida como 0, indicando que nenhuma opção foi selecionada.
//  As variáveis idc e idg também são zeradas, mostrando que a lista ainda está vazia.
//  Depois disso, um laço for percorre todo o vetor lista, atribuindo o valor 0 para cada posição.
//  Essa função é chamada no começo do programa para garantir que tudo comece organizado.

void inicializar()
{
    op = 0;
    idc = 0;
    idg = 0;
    for (int i = 0; i < 5; i++)
    {
        lista[i] = 0;
    }
}

// A função cor() permite ao usuário alterar a cor do texto no terminal.
// Ela exibe um menu com várias opções de cores disponíveis.
// O usuário escolhe uma opção e o programa aplica o código ANSI correspondente.
// O comando system("clear") é usado para limpar a tela antes de aplicar a cor.
// Caso o usuário digite uma opção inválida, o sistema informa o erro.
// Essa função é chamada quando o usuário escolhe a opção de mudar a cor no menu principal.

void cor()
{
    int opc;
    printf("************************\n");
    printf("* 0 - Reset            *\n");
    printf("* 1 - Vermelho         *\n");
    printf("* 2 - Verde            *\n");
    printf("* 3 - Amarelo          *\n");
    printf("* 4 - Azul             *\n");
    printf("* 5 - Roxo             *\n");
    printf("* 6 - Ciano            *\n");
    printf("************************\n");
    printf("Escolha a cor: ");
    scanf("%d", &opc);
    system("clear");
    switch (opc)
    {
    case 0:
        printf("\033[0m");
        break;
    case 1:
        printf("\033[1;31m");
        break;
    case 2:
        printf("\033[1;32m");
        break;
    case 3:
        printf("\033[1;33m");
        break;
    case 4:
        printf("\033[1;34m");
        break;
    case 5:
        printf("\033[1;35m");
        break;
    case 6:
        printf("\033[1;36m");
        break;
    default:
        printf("Opção inválida!");
        break;
    }
}

// A função menu() é responsável por exibir o menu principal na tela.
// É uma construção visual
void menu()
{
    system("clear");                                 // executa o comando limpar, limpa o terminal antes de exibir o menu
    printf("*************\n");                       // linhas de decoração
    printf("*          MENU PRINCIPAL         *\n"); // título do menu
    printf("*************\n");                       // linha decorativa
    printf("*                                 *\n"); // espaço decorativo
    printf("*   1 - CADASTRAR   *\n");               // opções do 1 - 9 para o usuário visualizar e selecionar
    printf("*   2 - CONSULTAR                 *\n"); // opção 2
    printf("*   3 - ALTERAR                   *\n"); // opção 3
    printf("*   4 - EXCLUIR                   *\n"); // opção 4
    printf("*   5 - ORDENAR CRESCENTE         *\n"); // opção 5
    printf("*   6 - ORDENAR DECRESCENTE       *\n"); // opção 6
    printf("*   7 - IMPRIMIR                  *\n"); // opção 7
    printf("*   8 - COR DA TELA               *\n"); // opção 8
    printf("*   9 - FINALIZAR                 *\n"); // opção 9
    printf("*                                 *\n"); // espaço decorativo
    printf("*************\n");                       // linha decorativa
}

// A função cadastrar() permite ao usuário inserir números na lista.
// Ela utiliza um loop do...while para permitir múltiplos cadastros em sequência,
void cadastrar()
{
    char r; // declara a variável 'r' do tipo char, armazena resposta do usuário (s ou n)
    do
    {                                            // inicia um loop do...while, garante q o bloco execute ao menos uma vez
        system("clear");                         // executa o comando 'limpar”, limpa o terminal a cada novo cadastro
        printf("Digite o número %d: ", idg + 1); // exibe ao usuário qual número está sendo cadastrado,
                                                 // usando idg+1 para mostrar a posição a partir do 1 e Ñ do 0
        scanf("%d", &lista[idg]);                // lê um inteiro digitado pelo usuário e armazena diretamente na posição 'idg' do array lista
        idg++;                                   // incrementa o idg, avançando para a próxima posição e atualizando o contador de elementos cadastrados
        if (idg < 5)// verifica se ainda há espaço no idg (capacidad máxima: 5)
        {                                                   
            printf("Deseja continuar cadastrando [s/n]: "); // se tiver espaço, pergunta ao usuário
                                                            // se deseja cadastrar mais um número
            scanf(" %c", &r);                               // lê o caractere digitado; o espaço antes de %c descarta caracteres residuais no buffer(como '\n')
        }
    } while ((tolower(r) == 's') && (idg < 5)); // condição de continuidade do loop:
    // tolower(r) converte a resposta para minúsculo, aceitando 'S' ou 's'
    //   == 's' verifica se a resposta foi positiva;
    //  && exige que as duas condições sejam verdadeiras simultaneamente;
    //  idg < 5 verifica se ainda há espaço no array;
    //  se o usuário digitou 'n' OU a lista está cheia, o loop encerra
}

_Bool consultar(int n)
{
    _Bool enc = false;
    idc = 0;
    while ((enc == false) && (idc < idg))
    {
        if (lista[idc] == n)
        {
            enc = true;
        }
        else
        {
            idc++;
        }
    }
    return enc;
}
// Função responsável por alterar um valor já existente na lista
void alterar(int nn, int p)
{                                             // O valor da posição vem pré-validado na sua condição de existência, portanto:
    lista[p] = nn;                            // o novo número passado como parâmetro substitui diretamente o valor da posição.
    printf("Número alterado com sucesso!\n"); // Exibibe uma mensagem de sucesso para o usuário .
    sleep(3);                                 // Tempo para permitir a visualiação da mensagem.
}

// Função vazia responsável por excluir um elemanto da lista
void excluir(int p)
{ // É passsado a posição 'p' do valor cuja existência verificada
    for (int i = p; i < idg - 1; i++)
    { // No laço for é deslocado todos os elementos à direita da posição removida uma posição para esquerda
        lista[i] = lista[i + 1];
    }
    idg--;                                    // Reduz o tamnho da lista após remoção para manipulação lógica da lista
    printf("Número excluído com sucesso!\n"); // Feedback ao usuário informando sucesso da operação.
    sleep(3);                                 // Tempo de pausa com o comando sleep para exibir mensagem na tela e o looping rodar novamente o menu.
}

// A função imprimir() percorre o array e exibe na tela todos os números cadastrados.
// Utiliza idg como limite do loop, garantindo que apenas posições preenchidas sejam impressas.
void imprimir()
{
    for (int i = 0; i < idg; i++)
    { // declara o contador 'i' iniciando em 0 (primeira posição do array);
      // o loop avança enquanto 'i' for menor que 'idg',
      // percorre apenas as posições com elementos cadastrados,

        printf("%d \n", lista[i]); // imprime o valor inteiro armazenado na posição 'i' do array,seguido de '\n' que quebra a linha a cada número impresso
    }
    sleep(3); // pausa a execução por 3 segundos, mantendo o resultado visível na tela antes que o fluxo retorne ao menu principal
}

void ordenarcrescente()
{            // Define função para ordenar em ordem crescente, não recebe parâmetros de entrada
    int aux; // Declaração da variavel auxiliar de tipo inteiro para armazenar valores temporariamente e realizar a troca de elementos.
    for (int i = 0; i < idg - 1; i++)
    { // Declaração do loop for, inicializando um contador em 0, definindo que esse loop  vai se repetir enquanto o contador for menor que o  indice geral da lista menos 1 (até a penultima posição preenchida), incrementando o contador ao final de cada loop.
        for (int y = i + 1; y < idg; y++)
        { // Declaração de um loop for aninhado, começando a contagem na segunda posição da lista, e se repetindo até a ultima posição. Incrementando o contador ao final de cada loop.
            if (lista[i] > lista[y])
            {                        // se o valor da posição i ( valor atual ), for maior que o valor da posição y:
                aux = lista[i];      // variável auxiliar vai receber o maior valor
                lista[i] = lista[y]; // posição da lista que tinha o maior valor, agora vazia, receberá o valor da posição "y" (valor menor que está sendo comparado)
                lista[y] = aux;      // posição da lista que tinha o valor menor, recebe o maior valor, ordenando assim no sentido menor -> maior
            }
        }
    }
    printf("Lista ordenada com sucesso!\n"); // Feedback visual para o usuário saber que a lista foi ordenada
    sleep(3);
}

void ordenardecrescente()
{            // Define função para ordenar em ordem decrescente, não recebe parâmetros de entrada
    int aux; // Declaração da variavel auxiliar de tipo inteiro para armazenar valores temporariamente e realizar a troca de elementos.
    for (int i = 0; i < idg - 1; i++)
    { // Declaração do loop for, inicializando um contador em 0, definindo que esse loop  vai se repetir enquanto o contador for menor que o  indice geral da lista menos 1 (até a penultima posição preenchida), incrementando o contador ao final de cada loop.
        for (int y = i + 1; y < idg; y++)
        { // Declaração de um loop for aninhado, começando a contagem na segunda posição da lista, e se repetindo até a ultima posição. Incrementando o contador ao final de cada loop.
            if (lista[i] < lista[y])
            {                        // se o valor da posição i ( valor atual ), for menor que o valor da posição y:
                aux = lista[i];      // variável auxiliar vai receber o menor valor
                lista[i] = lista[y]; // posição da lista que tinha o menor valor, agora vazia, receberá o valor da posição "y" (valor maior que está sendo comparado)
                lista[y] = aux;      // posição da lista que tinha o valor maior, recebe o menor valor, ordenando assim no sentido maior -> menor
            }
        }
    }
    printf("Lista ordenada com sucesso!\n"); // Feedback visual para o usuário saber que a lista foi ordenada
    sleep(3);
}

void main()
{
    setlocale(LC_ALL, "português");
    inicializar();
    do
    {
        int vnn;
        menu();
        printf("Escolha a opção desejada: ");
        scanf("%d", &op);
        system("clear");
        switch (op)
        {
        case 1:
            if (idg < 5)
            {
                cadastrar();
            }
            else
            {
                printf("Tabela cheia!\n");
                sleep(3);
            }
            break;
        case 2:
            printf("Digite o número que deseja procurar: ");
            scanf("%d", &num);
            if (consultar(num) == true)
            {
                printf("Número consta na lista\n");
            }
            else
            {
                printf("Número não consta na lista\n");
            }
            sleep(3);
            break;
        case 3:
            printf("Digite o número que deseja alterar: ");
            scanf("%d", &num);
            if (consultar(num) == true)
            {
                printf("Digite o novo número: ");
                scanf("%d", &vnn);
                alterar(vnn, idc);
            }
            else
            {
                printf("Número não consta na lista\n");
            }
            sleep(3);
            break;
        case 4:
            printf("Digite o número que deseja excluir: ");
            scanf("%d", &num);
            if (consultar(num) == true)
            {
                excluir(idc);
            }
            else
            {
                printf("Número não consta na lista\n");
            }
            sleep(3);
            break;
        case 5:
            ordenarcrescente();
            break;
        case 6:
            ordenardecrescente();
            break;
        case 7:
            imprimir();
            break;
        case 8:
            cor();
            break;
        default:
            if (op != 9)
            {
                printf("Opção inválida!\n");
                sleep(3);
                break;
            }
        }
    } while (op != 9);
    system("clear");
    printf("Sistema finalizado com sucesso!");
}
