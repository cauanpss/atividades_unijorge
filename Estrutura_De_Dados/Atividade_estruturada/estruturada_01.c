  #include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 50
#define TAM_NOME 100

typedef struct {
    int codigo;
    char nome[TAM_NOME];
    float salario;
} Funcionario;

void cadastrarFuncionarios(Funcionario vetor[], int n) {
    printf("\n--- CADASTRO DE FUNCIONÁRIOS ---\n");
    
    for (int i = 0; i < n; i++) {
        printf("\nFuncionário %d:\n", i + 1);
        
        printf("Código: ");
        scanf("%d", &vetor[i].codigo);
        
        printf("Nome: ");
        getchar();
        fgets(vetor[i].nome, TAM_NOME, stdin);
        vetor[i].nome[strcspn(vetor[i].nome, "\n")] = '\0';
        
        printf("Salário: R$ ");
        scanf("%f", &vetor[i].salario);
    }
}
void imprimirAcimaMedia(Funcionario vetor[], int n) {
    if (n == 0) {
        printf("\nNão há funcionários cadastrados.\n");
        return;
    }
    
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += vetor[i].salario;
    }
    float media = soma / n;
    
    printf("\n--- RESULTADO ---\n");
    printf("Média salarial: R$ %.2f\n", media);
    
    printf("\nFuncionários com salário ACIMA da média:\n");
    int encontrados = 0;
    
    for (int i = 0; i < n; i++) {
        if (vetor[i].salario > media) {
            printf("Nome: %s | Salário: R$ %.2f\n", vetor[i].nome, vetor[i].salario);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("Nenhum funcionário está acima da média.\n");
    } else {
        printf("\nTotal: %d funcionário(s) acima da média.\n", encontrados);
    }
}

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int N;
    
    do {
        printf("Digite a quantidade de funcionários a cadastrar (0 a %d): ", MAX_FUNCIONARIOS);
        scanf("%d", &N);
        
        if (N < 0 || N > MAX_FUNCIONARIOS) {
            printf("Valor inválido! Digite um número entre 0 e %d.\n", MAX_FUNCIONARIOS);
        }
    } while (N < 0 || N > MAX_FUNCIONARIOS);
    
    if (N > 0) {
        cadastrarFuncionarios(funcionarios, N);
        
        imprimirAcimaMedia(funcionarios, N);
    } else {
        printf("\nNenhum funcionário foi cadastrado.\n");
    }
    
    return 0;
}