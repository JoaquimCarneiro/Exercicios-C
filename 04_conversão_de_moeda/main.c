/* 
 * EXERCÍCIO 04 
 * Escrever um programa que sabendo um valor numa determinada moeda X 
 * determine o valor numa outra moeda Y considerando um fator de conversão F.​
 * Exemplo: Considerando X=5 e F=200.482 teremos Y=1002.41
 */

#include <stdio.h>

int main(){
    float moeda, fatorConversao = 200.482, moedaConvertida;
    printf("Qual é o valor que quer converter? ");
    scanf("%f", &moeda);
    printf("O valor original é: %.2f\n", moeda);
    moedaConvertida = moeda * fatorConversao;
    printf("O valor convertido é: %.2f\n", moedaConvertida);
    return 0;
}
