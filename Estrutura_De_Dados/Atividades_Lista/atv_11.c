#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int num[5] = {};
int neg = 0;
int pos = 0;
int zer = 0;

int main(){
    for (int i = 0; i < 5; i++) {
        printf("Digite um número:\n");
        scanf("%d", &num[i] );
    }
    
    for ( int n = 0; n < 5; n++){
        if(num[n] < 0){
            neg += 1;
        }
        
        if(num[n] > 0){
            pos += 1;
        }
        
        if(num[n] == 0){
            zer += 1;
        }
    }
    printf("A quantidade de números positivos é: %d \nA quantidade de números negativos é: %d \nA quantidade de zeros é: %d \n", pos, neg, zer);
    


    return 0;
}