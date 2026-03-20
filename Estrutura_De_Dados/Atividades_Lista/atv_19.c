#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int numeros[5] = {};
int positivos = 0;


int main(){
    printf("Digite 5 números: \n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &numeros[i]);
        
        if(numeros[i] > 0){
            positivos += 1;    
        }
    }
    printf("O total de números positivos é: %d", positivos);
    
    return 0;
}