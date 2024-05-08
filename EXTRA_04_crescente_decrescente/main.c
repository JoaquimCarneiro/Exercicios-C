/* EXERCÍCIO EXTRA 04 - Crescente decrescente 
 * Escreva um programa que solicite ao utilizador um número
 * e escreva em simultâneo a sequência crescente e decrescente entre 1 e esse número.
 */

#include <stdio.h>

int main(){
    int limite, i = 0;
    printf("Inserir um limite: ");
    scanf("%i", &limite);
    while (i < limite){
        printf("Crescente - %d | Decrescente - %d\n", i+1, limite-i);
        i++;
    }    
    return 0;
}