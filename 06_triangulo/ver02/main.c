/*
 * Problema 06
 * Ler três pontos e determinar se formam um triângulo ou não.
 * Um triângulo é sempre válido se a medida de cada um dos seus
 * lados é menor que a soma dos outros lados. Pode utilizar
 * o exercício anterior para calcular a medida dos lados dos triângulos.​
 * ---------------------------------------------------------------------
 * Exercício mal formulado: três pontos formam sempre um trinagulo
 * exepto quando este são colineares...
 * ---------------------------------------------------------------------
 * ver 02
 */
#include <stdio.h>
#include <math.h>

float distancia(float pontoA[], float pontoB[]);

int main() {
    // array precisa de
    float pontos[3][2], distAB, distBC, distCA;
    for (int i = 0; i < 3; ++i) {
        printf("Introduza coordenadas do ponto %c:\n\tX: ", 65+i);
        scanf("%f", &pontos[i][0]);
        printf("\tY: ");
        scanf("%f", &pontos[i][1]);
    }
    // calculo dos lados e verificação da não coincidência dos pontos
    if ((distAB = distancia(pontos[0], pontos[1])) == 0 ||
        (distBC = distancia(pontos[1], pontos[2])) == 0 ||
        (distCA = distancia(pontos[2], pontos[0])) == 0){
        printf("Pontos coincidentes");
        return 0;
    }
    // comparação dos tamanhos dos lados do triangulo
    if (distAB >= distBC + distCA ||
        distBC >= distAB + distCA ||
        distCA >= distAB + distBC ){
        printf("Triangulo inválido.");
        return 0;
    }
    printf("Triangulo válido.");
    return 0;
}

float distancia(float pontoA[], float pontoB[]){
    float distancia;
    if (pontoA[0] == pontoB[0] && pontoA[1] == pontoB[1]){
        distancia = 0;
    }else{
        //distancia = sqrt(pow(abs(pAx-pBx), 2) - pow(abs(pAy-pBy), 2));
        distancia = sqrtf(powf(pontoA[0]-pontoB[0],2) + powf(pontoA[1]-pontoB[1],2));
    }
    return distancia;
}