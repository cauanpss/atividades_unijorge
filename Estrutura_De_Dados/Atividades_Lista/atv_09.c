#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int n1, n2;

int main(){
    setlocale (LC_ALL, "");
    printf("Digite um número inteiro:\n");
    scanf("%d", &n1);
    printf("Digit um segundo número inteiro:\n");
    scanf("%d", &n2);

    int resto = n1 % n2; 
    
    printf("O resto da divisão entre %d e %d é %d",n1, n2, resto);

    return 0;
}