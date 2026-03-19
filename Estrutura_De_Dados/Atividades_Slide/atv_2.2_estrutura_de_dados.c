// FINALIZADO
// DÚVIDA COMO PERCORRER AS VOGAIS E IDENTIFICAR ACENTUAÇÃO SEM TER QUE AUMETNAR O VETOR DAS VOGAIS??? (alguma lib?)
#include <stdio.h>
#include <ctype.h>

char texto[50];
char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
int soma_vogais = 0;
int soma_consoantes = 0;
int tamanho_vogais = sizeof(vogais) / sizeof(vogais[0]);

int main()
{
    printf("Insira um texto: ");
    fgets(texto, 50, stdin);

    for (int n = 0; texto[n] != '\0'; n++)
    {
        if (isalpha(texto[n]))
        {
            int eh_vogal = 0;

            for (int i = 0; i < tamanho_vogais; i++)
            {
                if (texto[n] == vogais[i])
                {
                    soma_vogais++;
                    eh_vogal = 1;
                }
            }

            if (eh_vogal == 0)
            {
                soma_consoantes++;
            }
            eh_vogal = 0;
        }
    }
    printf("%s", texto);
    printf("A soma das vogais foi: %d\n", soma_vogais);
    printf("A soma das consoantes foi: %d\n", soma_consoantes);

    return 0;
}