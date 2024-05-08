/* 
 * Problema 19
 * Elabore um algoritmo que some os “n” primeiros números inteiros.
 * O valor de “n” é introduzido pelo utilizador.​
 * Faça o algoritmo com a estrutura PARA e outro com a estrutura ENQUANTO.
 * */

#include <stdio.h>

int main(){
    int limite, sum = 0, i = 1;
    printf("Somatório de Números\nIntroduza um limite: ");
    scanf("%i", &limite);
    printf("Resultado usando um ciclo enquanto (while)\n");

    while (i <= limite)
    {
        printf("\tsoma de %i com %i\n", sum, i);
        sum += i;
        i++;
    }
    printf("O total é %i\n\n", sum);

    printf("Resultado usando um ciclo enquanto (while)\n");
    sum = 0;
    for (int j = 1; j <= limite; j++)
    {
        printf("\tsoma de %i com %i\n", sum, j);
        sum += j;
    }
    printf("O total é %i\n", sum);
    
    return 0;
}