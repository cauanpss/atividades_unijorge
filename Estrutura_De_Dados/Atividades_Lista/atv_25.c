#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

float area_parcial[100];
int resposta_continuar;
bool continuar = true;
float area_total = 0;

int main()
{
    int i = 0;
    while (continuar && i < 99)
    {
        int numero = i / 2 + 1;
        
        printf("Qual comprimento do %dº cômodo: ", numero);
        scanf("%f", &area_parcial[i]);
        i++;

        printf("Qual largura do %dº cômodo: ", numero);
        scanf("%f", &area_parcial[i]);
        i++;

        printf("Deseja continuar? (1 = sim / 0 = nao): ");
        scanf("%d", &resposta_continuar);

        if (resposta_continuar == 0)
        {
            continuar = false;
        }
    }

    for (int n = 0; n < i; n += 2)
    {
        float area_comodo = area_parcial[n] * area_parcial[n + 1];
        area_total += area_comodo;
    }

    printf("A área total é %f m².", area_total);

    return 0;
}