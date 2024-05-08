/*
 * Exercício 1 ​
 * Escreva um programa que a partir de um número de horas introduzido pelo utilizador,
 * o converta em minutos ou em segundos, conforme opção do mesmo utilizador.
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void flushBuffer(){
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);
}

int main(){
    char opcao, tipo_convert[10];
    float horas;
    int horas_convert;
    
    printf("Introduza o número de horas: ");
    scanf("%f", &horas);

    flushBuffer();
    
    printf("Converter para Minutos ou Segundos? (M/S)");
    scanf("%c", &opcao);
    
    opcao = tolower(opcao);
    
    if (opcao != 's' && opcao != 'm'){
        printf("Opção inválida, nada a fazer.");
    }else{
        if(opcao == 'm'){
            horas_convert = horas*60;
            strcpy(tipo_convert, "minutos");
        }else{
            horas_convert = horas*3600;
            strcpy(tipo_convert, "segundos");
        }
        printf("%.2f horas são %i %s", horas, horas_convert, tipo_convert);
    }
    return 0;
}
