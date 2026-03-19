//CONCLUIDO
#include <stdio.h>

int num_1;
int num_2;



int maior(int num_1, int num_2)
{
    if (num_1 > num_2)
    {
        printf("O maior número é %d", num_1);
    }
    else if (num_2 > num_1)
    {
        printf("O maior número é %d", num_2);
    }
    else if (num_1 == num_2)
    {
        printf("Os números são iguais.");
    }
}

int main()
{
    printf("Digite o primeiro número: \n");
    scanf("%d", & num_1);
    printf("Digite o segundo número: \n");
    scanf("%d", &num_2);
    maior(num_1, num_2);
    
    return 0;
}