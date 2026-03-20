#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "");    
    printf("Os cinco primeiro números inteiros negativos:\n");     
    for(int i=0; i > -5  ; i--){
        printf("%d \n", i);
    }  

    return 0;
}