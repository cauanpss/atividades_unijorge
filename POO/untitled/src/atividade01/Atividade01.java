package atividade01;

import java.util.Scanner;

public class Atividade01 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int numero1, numero2, limiteSuperior, limiteInferior, somaInteiros, totalPares, totalImpares;

        somaInteiros = 0;
        totalImpares = 0;
        totalPares = 0;

        System.out.println("Digite um número: ");
        numero1 = sc.nextInt();
        System.out.println("Digite um segundo número: ");
        numero2 = sc.nextInt();

        if(numero1 > numero2){
            limiteSuperior = numero1;
            limiteInferior = numero2;
        }else{
            limiteSuperior = numero2;
            limiteInferior = numero1;
        }

        for(int i = limiteInferior; i <= limiteSuperior ; i++){

            if(i%2 == 0){
                System.out.println("O número " + i + " é par.");
                totalPares += 1;
            }else{
                System.out.println("O número " + i + " é impar.");
                totalImpares += 1;
            }

            somaInteiros += i;
        }

        System.out.println("O total da soma enter o intervalo de " + limiteInferior + " até " + limiteSuperior + " é de: " + somaInteiros + ".");
    }
}