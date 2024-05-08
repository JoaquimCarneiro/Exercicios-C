/* 
 * Exercício 2 
 * Escreva um programa que leia uma operação aritmética entre dois inteiros
 * e apresente o resultado dessa operação.
 * */

#include <stdio.h>
#include <ctype.h>

int main(){
    float num1, num2, total;
    char opercao, repetir;
    do{
        printf("#### Calculadora aritmética ####\n");
        printf("Introduza o primeiro numero: ");
        scanf("%f", &num1);
        printf( "Introduza a operação\n"
                "\tSoma -> +\n"
                "\tSubtração -> -\n"
                "\tMultiplicação -> *\n"
                "\tDivisão -> /\n"
                "\tResto da divisão -> %\n"
                "_: ");
        scanf(" %c", &opercao);
        printf("Introduza o segundo numero: ");
        scanf("%f", &num2);

        switch (opercao){
            case '+':
                printf("A soma de %.2f com %.2f é igual %.2f", num1, num2, num1 + num2);
                break;
            case '-':
                printf("A subtração de %.2f por %.2f é igual %.2f", num1, num2, num1 - num2);
                break;
            case '*':
                printf("A multiplicação de %.2f por %.2f é igual %.2f", num1, num2, num1 * num2);
                break;
            case '/':
                printf("A divisão de %.2f por %.2f é igual %.2f", num1, num2, num1 / num2);
                break;
            case '%':
                printf("O resto da divisão de %.2f por %.2f é igual %i", num1, num2, (int)num1 % (int)num2);
                break;
            default:
                printf("Operação inválida");
        }
        printf("\nFazer outro calculo? (S)");
        scanf(" %c", &repetir);
        repetir = tolower(repetir);
    } while (repetir == 's');
    return 0;
}
