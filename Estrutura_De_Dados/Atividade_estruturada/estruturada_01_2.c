#include <stdio.h>
#include <string.h>

#define TAM_NOME 100

typedef struct {
    int codigo;
    char nome[TAM_NOME];
    float salario;
} Funcionario;

void aplicarAumento(Funcionario *f, float percentual) {
    float aumento = f->salario * (percentual / 100.0);
    f->salario = f->salario + aumento;
    
    printf("\n[DENTRO DA FUNÇÃO]\n");
    printf("Aumento de %.1f%% aplicado: R$ %.2f\n", percentual, aumento);
    printf("Novo salário após aumento: R$ %.2f\n", f->salario);
}

int main() {
    Funcionario func;
    
    func.codigo = 1001;
    strcpy(func.nome, "Carlos Eduardo Silva");
    func.salario = 2850.75;
    
    printf("=== ANTES DO AUMENTO ===\n");
    printf("Código: %d\n", func.codigo);
    printf("Nome: %s\n", func.nome);
    printf("Salário original: R$ %.2f\n", func.salario);
    
    aplicarAumento(&func, 10.0);  
    
    printf("\n=== DEPOIS DO AUMENTO ===\n");
    printf("Código: %d\n", func.codigo);
    printf("Nome: %s\n", func.nome);
    printf("Salário atualizado: R$ %.2f\n", func.salario);
    
    float aumentoEsperado = 2850.75 * 0.10;
    printf("\n--- VERIFICAÇÃO ---\n");
    printf("Aumento esperado: R$ %.2f\n", aumentoEsperado);
    printf("Aumento real: R$ %.2f\n", func.salario - 2850.75);
    
    return 0;
}