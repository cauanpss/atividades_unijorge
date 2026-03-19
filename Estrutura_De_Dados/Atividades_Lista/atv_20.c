#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int numeros[10] = {};
int pares = 0;
int impares =0;

int main(){
    printf("Digite 10 números: \n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &numeros[i]);
        
        if((numeros[i] % 2) == 0) {
            pares += 1;    
        }
        else{
            impares += 1;
        }
    }
    printf("O total de números pares é: %d \nO total de números impares é: %d \n",pares, impares);
    
    return 1;
}