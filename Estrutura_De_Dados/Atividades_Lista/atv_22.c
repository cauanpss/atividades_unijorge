#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int n1;

int tabuada(int numero) {
        for(int i = 1; i <= 10; i++){
            int resultado = numero * i;
            printf("%d x %d = %d \n", numero, i, resultado);        
        }
    }

int main(){
    printf("Digite um número para saber a tabuada deste.\n");
    scanf("%d", &n1);
    tabuada(n1);
    
    return 0;
}