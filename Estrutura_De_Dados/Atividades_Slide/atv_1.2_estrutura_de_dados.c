#include <stdio.h>

int main() {
    int opcao = -1;

    do{
        printf("--------Bem vindo ao menu--------\n");
        printf("1-Saudações\n");
        printf("2-Data\n");
        printf("3-Sair\n");
        printf("Escolha sua opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Olá usuário!\n");
                break;
            
            case 2:
                printf("Hoje é dia 12/03\n");
                break;
            
            case 3:
                printf("Programa encerrado.\n");
                break;
        }

    } while (opcao != 3);

    return 0;

}