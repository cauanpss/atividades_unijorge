#include <stdio.h>

int main() {
    int  num = -1;
    int soma = 0 ;
    
    while (num !=0){
        printf("Digite um número: ");
        scanf("%d", &num);
        soma += num;
    }
    
    printf("A soma total é %d", soma);
    return 0;
}