#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int n1, n2;

int main(){
    setlocale (LC_ALL, "");
    printf("Digite um número inteiro:\n");
    scanf("%d", &n1);
    printf("Digite um segundo número inteiro:\n");
    scanf("%d", &n2);

    int quoc = n1 / n2; 
    
    printf("O quociente da divisão entre %d e %d é %d",n1, n2, quoc);

    return 1;
}