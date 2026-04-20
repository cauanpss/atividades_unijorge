#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char nome[50][50]; 
    int i, j, opcao;

    printf("Quantos nomes deseja cadastrar? ");
    scanf("%d", &i);

    if (i > 50) {
        printf("Limite maximo de 50 nomes.\n");
        i = 50;
    }

    for (j = 0; j < i; j++) {
        printf("Digite o %dº nome: ", j + 1);
        scanf("%s", nome[j]);
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    do {
        j = rand() % i; // gera número entre 0 e i-1
        printf("O nome sorteado foi: %s\n", nome[j]);

        printf("Deseja sortear novamente? 1- Sim / 2- Nao: ");
        scanf("%d", &opcao);

    } while (opcao != 2);

    return 0;
}