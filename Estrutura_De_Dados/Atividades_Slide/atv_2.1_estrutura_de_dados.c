//FINALIZADO
#include <stdio.h>

int main(){
    int matriz[3][3];
    int i, j;
    int diagonal_principal[3];

    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            printf("Digite um número para a posição [%d][%d] da matriz:\n", i, j );
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
        
    printf("A diagonal principal é ");
    for (i=0; i<3; i++) {
        diagonal_principal[i] = matriz[i][i];
        printf("%d, ", diagonal_principal[i]);
    }

    return 0;       
    
} 