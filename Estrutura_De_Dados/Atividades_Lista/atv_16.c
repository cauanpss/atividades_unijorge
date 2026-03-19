#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int idades[3] = {};
int idade_total;

int main(){
    printf("Digite a idade de três pessoas:\n");
    for(int i=1; i < 4; i++ ){
        printf("%dº pessoa:\n", i );
        scanf("%d", &idades[i]);
        idade_total += idades[i];
    }
    
    int media = idade_total / 3;
    
    printf("A média de idade das 3 pessoas é: %d ", media);
    
    return 1;
}