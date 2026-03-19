#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

float num[5] = {};
float total = 0;

int main(){
    for(int i = 0 ; i < 5 ; i++){
        printf("Digite um número:\n");
        scanf("%f", &num[i]);
    }
    for(int n = 0; n < 5; n++ ){
        total += num[n];
    }

    float media = total / 5;

    printf("A média das notas é: %.2f", media);

    return 1;
}
