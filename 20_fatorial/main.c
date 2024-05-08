/* 
 * Problema 20​
 * Construa o algoritmo do fatorial de um número,
 * isto é o produto de todos os inteiros desde 1 até ao número escolhido.
 * */

#include <stdio.h>

int main(){
    int fator, resultado = 1;
    printf("Introduza o fatorial pretendido: ");
    scanf("%i", &fator);
    for (int i = 1; i <= fator; i++){
        resultado *= i;
    }
    printf("O fatorial de %i é igual a %i.", fator, resultado);
    return 0;
}