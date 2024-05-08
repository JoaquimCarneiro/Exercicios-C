/* 
 * Problema 23
 * ​Faça um algoritmo que calcule o valor de S onde:
 * S = 1/1 + 3/2 + 5/3 + 7/4 ... 99/50
 * e
 * S = 1/1 - 2/4 + 3/9 - 4/16 + 5/25 ... 10/100
 * */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(){
    char opcao;
    printf( "escolha entre as equações:\n"
            "\tA: S = 1/1 + 3/2 + 5/3 + 7/4 ... 99/50\n"
            "\tB: S = 1/1 - 2/4 + 3/9 - 4/16 + 5/25 ... 10/100\n"
            "_: ");
    scanf("%c", &opcao);
    
    opcao = tolower(opcao);

    int divisor = 1;
    float dividendo = 1, soma = 0, divisao = 0;
    
    if(opcao == 'a'){
        printf("Calculo de S = 1/1 + 3/2 + 5/3 + 7/4 ... 99/50\n");
        while (divisor < 50){
            divisao = dividendo / divisor;
            soma += divisao;
            printf("%.0f/%i\t= %.2f\tS = %.2f\n", dividendo, divisor, divisao, soma);
            //dividendo += divisor;
            dividendo += 2;
            divisor ++;
        }
    }else if(opcao == 'b'){
        printf("Calculo de S = 1/1 - 2/4 + 3/9 - 4/16 + 5/25 ... 10/100\n");
        while (dividendo <= 10){
            divisao = dividendo / divisor;
            if (((int)dividendo % 2) == 0){
                soma -= divisao;
            }else{
                soma += divisao;
            }            
            printf("%.0f/%i\t= %.2f\tS = %.2f\n", dividendo, divisor, divisao, soma);
            dividendo ++;
            divisor = pow(dividendo, 2);
        }
    }
    return 0;
}
