//FINALIZADO

#include <stdio.h>

int main()
{
    int vetor[5];
    int maior;
    int menor;
    int soma;
    float media;
    int tamanho_do_vetor = sizeof(vetor) / sizeof(vetor[0]);

    soma = 0;
    media = 0;

    for (int n = 0; n < tamanho_do_vetor; n++)
    {
        printf("Digite um número para ser armazenado no vetor: \n");
        scanf("%d", &vetor[n]);
    }

    maior = vetor[0];
    menor = vetor[0];

    for (int i = 0; i < tamanho_do_vetor; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }

        else if (vetor[i] < menor)
        {
            menor = vetor[i];
        };
    }

    for (int i = 0; i < tamanho_do_vetor; i++)
    {
        soma += vetor[i];
    }

    media = soma / tamanho_do_vetor;

    printf("O maior elemento do vetor é %d\n", maior);
    printf("O menor elemento do vetor é %d\n", menor);
    printf("A soma é: %d\n", soma);
    printf("A média é: %.2f\n", media);
}