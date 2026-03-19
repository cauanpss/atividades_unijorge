#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int num;

int main(){
    printf("Digite um número:\n");
    scanf("%d", &num);

    printf("Os 5 números sucessores são:\n");

    for(int n = 0; n < 5; n++ ){
        num -= 1;
        printf("%d", num);
    }

    return 1;
}
