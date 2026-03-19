#include <stdio.h>

float calculo_imc(double peso, double altura) {
    float imc = peso / (altura * altura);
    return imc;
    
}

int continuar() {
    int continuar;
    printf("Você deseja refazer o calculo de IMC?\n (1) Sim\n(2) Não\n");
    scanf("%d", &continuar);
    return continuar;
}

int main() {
    int opcao = 1;
    
    do {
        double imc, altura, peso; 
    
        int idade;
    
        
        printf("Qual sua idade?\n");
        scanf("%d", &idade);
        
        printf("Qual seu peso?\n");
        scanf("%lf", &peso);
        
        printf("Qual sua altura?\n");
        scanf("%lf", &altura);
        
        imc = calculo_imc( peso, altura);
        printf("Seu IMC é %.2f ", imc);
        
        if (imc < 18.5) {
            printf("Você está bem abaixo do peso. (Magreza)\n");
        }
        
        else if (18.5 <= imc && imc <= 24.9) {
            printf("Você está com peso ideal.\n");
            
        }
        
        else if (25 <= imc && imc <= 29.9) {
            printf("Você está um acima do peso. (Sobrepeso)\n");
        }
        
        else if (30 <= imc && imc <= 34.9) {
            printf("Você está acima do peso. (Obesidade grau 1)\n");
        }
        
        else if (35 <= imc && imc <= 39.9 ) {
            printf("Você está acima do peso. (Obesidade grau 2\n");
        }
        
        else if ( imc >= 40) {
            printf("Você está acima do peso. (Obesidade grau 3\n");
        }
        
        opcao = continuar();
        
    } while(opcao == 1);
    
    
    return 0;
}