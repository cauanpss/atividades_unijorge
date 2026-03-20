#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

float cateto_adjacente;
float cateto_oposto;
float hipotenusa;

int main(){
    printf("Digite o comprimento do cateto adjacente:\n");
    scanf("%f", &cateto_adjacente);
    printf("Digite o valor do cateto oposto:\n");
    scanf("%f",&cateto_oposto);
    
    hipotenusa = sqrt(pow(cateto_adjacente, 2) + pow(cateto_oposto, 2));
    printf("A hipotenusa tem valor %.2f", hipotenusa);
    
    return 0;
}