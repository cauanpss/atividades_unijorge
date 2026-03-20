#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int n1;
int n2;
int produto;


int main(){
    printf("Digite dois números:\n");
    scanf("%d \n %d", &n1, &n2);

    for( int i = 0; i < n2; i++){
        produto += n1;
    }
    printf("%d", produto);

    return 0;
}