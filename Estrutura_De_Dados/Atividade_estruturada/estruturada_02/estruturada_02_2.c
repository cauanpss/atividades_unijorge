#include <stdio.h>
#define MAX 100

void inserirSemRepetir(int v[], int valor, int *pos, int max);

void listar(int v[], int qtd);

void intercalar(
    int v1[], int qtd1,
    int v2[], int qtd2,
    int v3[], int *qtd3);

void intersecao(
    int v1[], int qtd1,
    int v2[], int qtd2,
    int v3[], int *qtd3);

void uniao(
    int v1[], int qtd1,
    int v2[], int qtd2,
    int v3[], int *qtd3);

void removerPeloIndice(int v[], int *quantidade, int indice);

int indice;

int buscar(int v[], int qtd, int valor);

int main()
{

    // variáveis sendo inicializadas localmente
    int lista1[MAX];
    int lista2[MAX];

    int qtd1 = 0;
    int qtd2 = 0;

    int valor;
    int i;

    int n1;

    // inserção dos elementos em listas

    printf("Quantos elementos deseja inserir na lista 1? ");
    scanf("%d", &n1);

    for (i = 0; i < n1; i++)
    {

        printf("Digite um valor: ");
        scanf("%d", &valor);

        inserirSemRepetir(lista1, valor, &qtd1, MAX);
    }

    int n2;

    printf("\nQuantos elementos deseja inserir na lista 2? ");
    scanf("%d", &n2);

    for (i = 0; i < n2; i++)
    {

        printf("Digite um valor: ");
        scanf("%d", &valor);

        inserirSemRepetir(lista2, valor, &qtd2, MAX);
    }

    printf("\nLista 1:\n");
    listar(lista1, qtd1);

    printf("\nLista 2:\n");
    listar(lista2, qtd2);

    // lista itnercalada
    int listaIntercalada[MAX * 2];
    int qtdIntercalada;

    intercalar(
        lista1, qtd1,
        lista2, qtd2,
        listaIntercalada, &qtdIntercalada);

    printf("\nLista intercalada:\n");
    listar(listaIntercalada, qtdIntercalada);

    // lista de intercessão

    int listaIntersecao[MAX];
    int qtdIntersecao;

    intersecao(
        lista1, qtd1,
        lista2, qtd2,
        listaIntersecao, &qtdIntersecao);

    printf("\nIntersecao:\n");
    listar(listaIntersecao, qtdIntersecao);

    // lista de união

    int listaUniao[MAX * 2];
    int qtdUniao;

    uniao(
        lista1, qtd1,
        lista2, qtd2,
        listaUniao, &qtdUniao);

    printf("\nUniao:\n");
    listar(listaUniao, qtdUniao);

    // removendo por indice

    printf("\nDigite o indice para remover da lista uniao: ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= qtdUniao)
    {

        printf("Indice invalido!\n");
    }
    else
    {

        removerPeloIndice(listaUniao, &qtdUniao, indice);

        printf("\nLista apos remocao:\n");
        listar(listaUniao, qtdUniao);
    }

    return 0;
}

int buscar(int v[], int qtd, int valor)
{

    int i;

    for (i = 0; i < qtd; i++)
    {

        if (v[i] == valor)
        {
            return i;
        }
    }

    return -1;
}

void inserirSemRepetir(int v[], int valor, int *pos, int max)
{

    if (*pos >= max)
    {

        printf("ERRO: lista cheia!\n");
        return;
    }

    if (valor == 0)
    {

        printf("ERRO: não são permitidos valores nulos!\n");
        return;
    }

    if (buscar(v, *pos, valor) != -1)
    {

        printf("ERRO: valor repetido!\n");
        return;
    }

    v[*pos] = valor;
    (*pos)++;
}

void listar(int v[], int qtd)
{

    int i;

    for (i = 0; i < qtd; i++)
    {

        printf("%d ", v[i]);
    }

    printf("\n");
}

void intercalar(
    int v1[], int qtd1,
    int v2[], int qtd2,
    int v3[], int *qtd3)
{

    int i = 0;
    int n = 0;

    *qtd3 = 0;

    while (i < qtd1 || n < qtd2)
    {

        if (i < qtd1)
        {

            v3[*qtd3] = v1[i];
            (*qtd3)++;
            i++;
        }

        if (n < qtd2)
        {

            v3[*qtd3] = v2[n];
            (*qtd3)++;
            n++;
        }
    }
}

void uniao(
    int v1[], int qtd1,
    int v2[], int qtd2,
    int v3[], int *qtd3)
{

    int i;

    *qtd3 = 0;

    for (i = 0; i < qtd1; i++)
    {

        inserirSemRepetir(v3, v1[i], qtd3, MAX);
    }

    for (i = 0; i < qtd2; i++)
    {

        inserirSemRepetir(v3, v2[i], qtd3, MAX);
    }
}

void intersecao(
    int v1[], int qtd1,
    int v2[], int qtd2,
    int v3[], int *qtd3)
{

    int i;

    *qtd3 = 0;

    for (i = 0; i < qtd1; i++)
    {

        if (buscar(v2, qtd2, v1[i]) != -1)
        {

            v3[*qtd3] = v1[i];
            (*qtd3)++;
        }
    }
}

void removerPeloIndice(int v[], int *quantidade, int indice)
{

    int i;

    for (i = indice; i < *quantidade - 1; i++)
    {

        v[i] = v[i + 1];
    }

    (*quantidade)--;
}