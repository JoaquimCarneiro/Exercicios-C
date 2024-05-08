/* EXERCÍCIO EXTRA 5 - Desenhar um quadrado
 * Escreva um programa que solicite ao utilizador um número (n)
 * e um carater e em seguida terá que preencher n linhas,
 * cada uma delas com n carateres.
 */

#include <stdio.h>

int main(){
    int n;
    char caractere;
    printf("Introduza um numero: ");
    scanf("%i", &n);
    printf("Introduza um caractere: ");
    scanf(" %c", &caractere);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%c", caractere);
        }
        printf("\n");
    }
    return 0;
}
