/* 
 * Problema 22
 * Faça um algoritmo que calcule os múltiplos de um número
 * até um determinado valor definido por limite,
 * e calcule os seus divisores.
 */

#include <stdio.h>

int main(){
    int num, limite, total, resto, contador = 1;
    printf("Calcular os multiplos de um numero, até um limite, e os seus divisores.\n\tIntroduza um numero: ");
    scanf("%i", &num);
    printf("\tIntroduza um limite: ");
    scanf("%i", &limite);
    printf("\nMultiplos do numero %i:\n", num);
    if(limite < num){
        printf("Limite inferior ao numero inicial, nada a fazer.\n");
    }else{
        while (total < limite){
            total = num * contador;
            printf("\t%i x %i = %i\n", num, contador, total);
            contador ++;
        }
    }
    printf("\nDivisores do numero %i:\n\t", num);
    for (int i = num; i > 0; i--){
        if(num % i == 0){
            printf("%i ", i);
        }
    }
    
    return 0;
}
