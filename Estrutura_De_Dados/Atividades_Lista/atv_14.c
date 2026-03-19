#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int num;

int main(){
    for(int i = 0 ; i < 5 ; i++){
        printf("Digite um número:\n");
        scanf("%d", &num);
        printf("O número digitado foi %d", num);
    }


    return 1;
}
