#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    float soma = 0.0;
    float notas[3];
        
    for (int i = 0; i < 3; i++) {
        
        do {
            printf("Digite a nota:");
            scanf("%f", &notas[i]);
            
            if (notas[i] < 0 || notas[i] > 10) {
            printf("Nota inválida. Digite uma nota entre 0 e 10.\n");
        }
            
        } while (notas[i] < 0 || notas[i] > 10); 
        
        
        soma += notas[i];
    };
    
    float media = soma / 3;
    printf("Sua média é: %.2f\n", media);
    
    if (media >= 6.0) {
        printf("Aprovado\n");
        }
        
        else if (media >= 4.0 && media < 6.0) {
        printf("Você deve fazer Av4\n");
        
        float av4;
        
        do {
            printf("Digite a nota da Av4:");
            scanf("%f", &av4);
        
            if (av4 < 0 || av4 > 10) {
                printf("Nota inválida. Digite uma nota entre 0 e 10.\n");
            }
            
        } while (av4 < 0 || av4 > 10);

            media = (media +  av4) / 2;
            
            if (media >= 6.0) {
                printf("Você foi aprovado\n");
            } 
            
            else {
                printf("Você foi reprovado\n");
            }         
    
        }
        
        else {
            printf("Você foi reprovado\n");
        }
        
        Sleep(30000);
    
    return 0;

}