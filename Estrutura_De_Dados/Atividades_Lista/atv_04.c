#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

float n1, n2;

int main(){
    setlocale (LC_ALL, "");
    printf("Digite um número:\n");
    scanf("%f", &n1);
    printf("Digite outro número:\n");
    scanf("%f", &n2);

    float mult = (n1 * n2);

    printf("A multiplicação de %.2f e %.2f é %.2f.",n1, n2, mult);


    return 0;
}