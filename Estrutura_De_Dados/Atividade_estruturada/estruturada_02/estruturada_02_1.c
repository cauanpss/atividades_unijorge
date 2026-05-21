#include <stdio.h>
void Teste1(int);
void Teste2(int *);
int Teste3(int);
int x = 20;

void Teste1(int numero)
{
    numero = numero + x; 
    x++; // 
}
void Teste2(int *numero)
{
    int valor = 100; //só existe localmente
    *numero = *numero + valor; // 
    x++;
}
int Teste3(int n)
{
    int valor = 200;
    n = n + valor;
    x--;
}

int main(void)
{
    int numero = 10, outroNumero; // numero começa em 10
    Teste1(numero); //numero passa a 30 dentro da função, mas informação é destruida dentro do escopo da mesma por não ter retorno, numero permanece sendo 10.
    printf("Valor de numero (apos Teste1) = %d\n", numero); //exibe 10
    printf("X = %d\n", x);// exibe 21 pois x é incrementado ao final da execução da função Teste1()
    Teste2(&numero);// através do ponteiro, numero (10) é incrementado pelo valor 100 passando a 110
    printf("Valor de numero (apos Teste2) = %d\n", numero);//110 é exibido
    printf("X = %d\n", x); // x é incrementado ao final de Teste2 passando a 22 
    outroNumero = Teste3(numero); // O valor n de Teste3(n), aqui é 110(valor atual da variavel numero), após processamento torna-se 310 (numero + valor), e x é decrementado em 1, (22-1 = 21)
    printf("Valor de outro numero (apos Teste3) = %d\n", outroNumero); //exibe 310
    printf("X = %d\n", x); //exibe 21
    return 0; //remove todos os valores da memória.
}

// 1:

// a)
// Variáveis globais:
// void Teste1(int);
// void Teste2(int *);
// int Teste3(int);
// int x = 20;

// Variáveis locais:
// em main(): numero e outroNumero
// em Teste1: numero (parametro)
// em Teste2: *numero (parametro), e valor
// em Teste3: n (parametro),e  valor

// b)
// Teste1(int numero) -> passagem por valor
// Teste2(int *numero) -> passagem por referência
// Teste3(int n) -> passagem por valor

// c)
// Comentário descrevendo processamento no código.

// d)
    // "Valor de numero (apos Teste1) = 10
    // X = 21
    // Valor de numero (apos Teste2) = 110
    // X = 22
    // Valor de outro numero (apos Teste3) = 310
    // X = 21"

