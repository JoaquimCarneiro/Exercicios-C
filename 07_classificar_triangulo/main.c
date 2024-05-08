/* 
 * Problema 07
 * Classificar um triângulo quanto aos lados.​
 * 3 lados iguais - equilátero;
 * 2 lados iguais - isósceles;
 * todos diferentes - escaleno 
 */
#include <stdio.h>

int main(){
    float lados[3];
    printf( "Classificar um triangulo relativamente ao tamanho dos seus lados.\n"
            "inserir os tamanhos dos lados:\n");
    //obter lados do triangulo
    for (int i = 0; i < 3; i++){
        printf("\tLado %i: ", i+1);
        scanf("%f", &lados[i]);
    }
    //determinar tipo de triangulo
    if (lados[0] >= lados[1] + lados[2] ||
        lados[1] >= lados[0] + lados[2] ||
        lados[2] >= lados[0] + lados[1]){
        printf("Triangulo Inválido");
    }else if (lados[0] == lados[1] && lados[1] == lados[2]){
        printf("Triangulo Equilátero");
    }else if (lados[0] != lados[1] && lados[1] != lados[2] && lados[2] != lados[0]){
        printf("Triangulo Escaleno");
    }else{
        printf("Trinagulo Isósceles");
    }
    
    return 0;
}
