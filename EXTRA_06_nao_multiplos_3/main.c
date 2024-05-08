/* EXERCÍCIO EXTRA 6 - Não multiplo de 3 até multiplo de 10
 * Escreva um programa que solicite ao utilizador um número.
 * Em seguida, o programa devolve todos os números inteiros a partir desse número,
 * exceto os múltiplos de 3.
 * O programa termina quando encontrar o primeiro múltiplo de 10.​
 * Exemplo:​
 *      N  = 13​
 *      Resultado: 13, 14, 16, 17, 19
 * */

#include <stdio.h>

int main(){
    int n;
    printf("Introduza um numero: ");
    scanf("%i", &n);
    while (n % 10 != 0){
        if(n % 3 != 0){
            printf("%i", n);
            if ((n + 1) % 10 != 0){
                printf(", ");
            }
        }
        n++;
    }
    printf("\n");
    return 0;
}
