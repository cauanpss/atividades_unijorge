#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    for(float i = 50, n = 1; i >= 1 && n <= 50 ; i--, n++){
        float s = i / n ; 
        printf("%.2f\n", s);
    }

    return 0;
}