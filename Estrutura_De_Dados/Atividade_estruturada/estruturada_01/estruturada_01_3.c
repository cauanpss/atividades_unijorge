#include <stdio.h>
#include <string.h>

struct Notebook {
    char marca[50];
    char modelo[50];
    int ramGB;
    float preco;
};

int main(){
    int n_notebooks, i;
    int indiceMaiorRAM = 0;
    
    printf("Quantos notebook deseja cadastrar?\n") ;
    scanf("%d", &n_notebooks);

    struct Notebook lista_notebooks[n_notebooks];

    for( i = 0; i < n_notebooks; i++){

        printf("\nNotebook %d\n", i + 1);

        printf("Marca: ");
        scanf("%s", lista_notebooks[i].marca);

        printf("Modelo: ");
        scanf("%s", lista_notebooks[i].modelo);

        printf("Quantidade de RAM (GB): ");
        scanf("%d", &lista_notebooks[i].ramGB);

        printf("Preco: ");
        scanf("%f", &lista_notebooks[i].preco);
    }

    for (i = 1; i < n_notebooks; i++) {
        if (lista_notebooks[i].ramGB > lista_notebooks[indiceMaiorRAM].ramGB) {
            indiceMaiorRAM = i;
        }
    }

    printf("\nNotebook com maior quantidade de RAM:\n");
    printf("Marca: %s\n", lista_notebooks[indiceMaiorRAM].marca);
    printf("Modelo: %s\n", lista_notebooks[indiceMaiorRAM].modelo);
    printf("Preco: R$ %.2f\n", lista_notebooks[indiceMaiorRAM].preco);
    

    return 0;
}