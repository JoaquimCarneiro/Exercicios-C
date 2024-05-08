/*
 * Problema 05 - Distância entre dois pontos
 * Calcular a distância em dois pontos, sendo que cada ponto é definido pelas coordenadas (X,Y). ​
 * Caso sejam coincidentes mostrar mensagem “Pontos Coincidentes”.​
 * NOTA: distancia = √((x2-x1)² + (y2-Y1)²)
*/

#include <stdio.h>
#include <math.h>

int main(){
    float pAx, pAy, pBx, pBy, distancia;
    printf("Introduza coordenadas do ponto A:\n\tX: ");
    scanf("%f", &pAx);
    printf("\tY: ");
    scanf("%f", &pAy);
    printf("Introduza coordenadas do ponto B:\n\tX: ");
    scanf("%f", &pBx);
    printf("\tY: ");
    scanf("%f", &pBy);
    if (pAx == pBx && pAy == pBy){
        printf("Pontos Coincidentes");
    }else{
        //distancia = sqrt(pow(abs(pAx-pBx), 2) - pow(abs(pAy-pBy), 2));
        distancia = sqrt(pow(pAx-pBx,2) + pow(pAy-pBy,2));
        printf("A distancia entre os pontos A e B é de %.2f", distancia);
    }
    return 0;
}
