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

    int pow_n1_n2 = pow(n1, n2);
    int pow_n2_n1 = pow(n2, n1);
    
    printf(" %d elevado a %d  é %d", n1, n2, pow_n1_n2);
    printf(" %d elevado a %d  é %d", n2, n1, pow_n2_n1);

    return 1;
}