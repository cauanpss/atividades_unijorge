#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

int resposta_sexo;
float resposta_altura;

bool resposta_altura_primeira_vez = true;

float maior_altura = 0;
float menor_altura;

int homens = 0;
float mulheres = 0;

float total_altura_mulheres = 0;
float mulher_menor_1_68 = 0;
float percentual_abaixo_1_68 = 0;

int main()
{

    do
    {
        printf("Digite sua altura:\n");
        scanf("%f", &resposta_altura);

        if (resposta_altura <= 0)
        {
            break;
        }
        else
        {
            printf("Qual sexo: masculino[1], femino[2]:\n");
            scanf("%d", &resposta_sexo);

            if (resposta_sexo == 1)
            {
                homens += 1;
            }
            else if (resposta_sexo == 2)
            {
                mulheres += 1;
            }

            if (resposta_altura_primeira_vez)
            {
                menor_altura = resposta_altura;
                maior_altura = resposta_altura;
                resposta_altura_primeira_vez = false;
            }

            if (resposta_altura > maior_altura)
            {
                maior_altura = resposta_altura;
            }

            if (resposta_sexo == 2 && resposta_altura < 1.68)
            {
                mulher_menor_1_68 += 1;
            }

            if (resposta_sexo == 2)
            {
                total_altura_mulheres += resposta_altura;
            }

            if (resposta_altura <= menor_altura)
            {
                menor_altura = resposta_altura;
            }
        }
    } while (resposta_altura > 0);

    float media_altura_mulheres = total_altura_mulheres / mulheres;
    percentual_abaixo_1_68 = (mulher_menor_1_68 / mulheres) * 100;

    printf("A maior altura do grupo é: %.2f\n", maior_altura);
    printf("O total de homens do grupo é: %d\n", homens);
    printf("A média de altura das mulheres é: %.2f\n", media_altura_mulheres);
    printf("O percentual de mulheres abaixo de 1,68 é: %.2f%%", percentual_abaixo_1_68);

    return 1;
}