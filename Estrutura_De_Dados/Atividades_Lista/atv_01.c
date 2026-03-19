#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "");    
    printf("Os cinco primeiro números inteiros:\n");     
    for(int i=0; i <= 4 ; i++){
        printf("%d \n", i);
    }  

    return 1;
}