#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int n1, n2;

int main(){
    setlocale (LC_ALL, "");
    printf("Digite um número:\n");
    scanf("%d", &n1);
    int n2 = n1 - 1;
    printf("O número antecessor a %d é %d", n1, n2);

    return 1;
}