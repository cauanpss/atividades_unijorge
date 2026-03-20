#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int num;

int main(){
    printf("Digite um número:\n");
    scanf("%d", &num);

    if(num % 2 == 0){
        for (int i = 0; i < 10; i++){
            num += 2;
            printf("%d \n", num);
        }
    }
    
    else{
        printf("Esse é um número ímpar.");
    }

    return 0;
}