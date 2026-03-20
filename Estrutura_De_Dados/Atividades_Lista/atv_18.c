#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int numero = 2 ;

int main(){
    for(int i = 0; i <= 10; i++){
        int numero_atual = numero * i;
        printf("%d x %d = %d \n",numero, i, numero_atual);
    }
    
    
    return 0;
}