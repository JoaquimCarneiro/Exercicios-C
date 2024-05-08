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
 * ver 01
 */

#include <stdio.h>
#include <math.h>

int main()
{
    float Ax, Ay, Bx, By, Cx, Cy, distAB, distBC, distCA;
    printf("Introduza coordenadas do ponto A:\n\tX: ");
    scanf("%f", &Ax);
    printf("\tY: ");
    scanf("%f", &Ay);
    printf("Introduza coordenadas do ponto B:\n\tX: ");
    scanf("%f", &Bx);
    printf("\tY: ");
    scanf("%f", &By);
    printf("Introduza coordenadas do ponto C:\n\tX: ");
    scanf("%f", &Cx);
    printf("\tY: ");
    scanf("%f", &Cy);
    // calculo segmento de reta AB
    if (Ax == Bx && Ay == By){
        printf("Pontos A e B Coincidentes, triangulo inválido.");
        return 0;
    }else{
        //distancia = sqrt(pow(abs(pAx-pBx), 2) - pow(abs(pAy-pBy), 2));
        distAB = sqrt(pow(Ax-Bx,2) + pow(Ay-By,2));
        printf("A distancia entre os pontos A e B é de %.2f\n", distAB);
    }
    // calculo segmento de reta BC
    if (Bx == Cx && By == Cy){
        printf("Pontos B e C Coincidentes, triangulo inválido.");
        return 0;
    }else{
        //distancia = sqrt(pow(abs(pAx-pBx), 2) - pow(abs(pAy-pBy), 2));
        distBC = sqrt(pow(Bx-Cx,2) + pow(By-Cy,2));
        printf("A distancia entre os pontos B e C é de %.2f\n", distBC);
    }
    // calculo segmento de reta CA
    if (Cx == Ax && Cy == Ay){
        printf("Pontos C e A Coincidentes, triangulo inválido.");
        return 0;
    }else{
        //distancia = sqrt(pow(abs(pAx-pBx), 2) - pow(abs(pAy-pBy), 2));
        distCA = sqrt(pow(Cx-Ax,2) + pow(Cy-Ay,2));
        printf("A distancia entre os pontos C e A é de %.2f\n", distCA);
    }

    // comparação dos tamanhos dos lados do triangulo (pode ser simplificado usand ORs)
    if (distAB >= distBC + distCA ){
        printf("Triangulo inválido.");
        return 0;
    }
    if (distBC >= distAB + distCA ){
        printf("Triangulo inválido.");
        return 0;
    }
    if (distCA >= distAB + distBC ){
        printf("Triangulo inválido.");
        return 0;
    }
    
    printf("Triangulo válido.");
    return 0;
}
