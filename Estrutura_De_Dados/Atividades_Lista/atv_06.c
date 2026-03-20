#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int n1, n2;

int main(){
    setlocale (LC_ALL, "");
    printf("Digite um número:\n");
    scanf("%d", &n1);
    int n2 = sqrt(n1);
    printf("a raiz quadrada de  %d é %d", n1, n2);

    return 0;
}