/* EXERCÍCIO EXTRA 8 - IMC 
 * Escreva um programa que permita determinar o índice de massa corporal (IMC) de várias pessoas.​
 * Caso o índice seja inferior a 19, deve surgir uma mensagem a indicar “deve ganhar peso”.​
 * Caso o índice seja superior a 25, deve surgir uma mensagem a indicar “deve perder peso”.​
 * Caso contrário, deve surgir uma mensagem a indicar “peso ótimo”.​
 * No final, deve ainda apresentar os valores mínimos, médios e máximos para altura, peso e índice de massa corporal
 * IMC = Peso (kg) / Altura^2(m)​
 * */

#include <stdio.h>

#ifdef _WIN32
    #define CLEARCMD "cls"
#else
    #define CLEARCMD "clear"
#endif

float imc(float peso, float altura);

int main(){
    int n_imc = 0;
    char continuar;
    float peso, altura,
    altura_min, altura_max, altura_tot = 0,
    peso_min, peso_max, peso_tot = 0,
    imc_loc, imc_min, imc_max, imc_tot = 0;
    do{
        system(CLEARCMD);
        printf("-------------------------------------------------\n");
        printf("Calculadora de indice de massa corporal\n");
        printf("-------------------------------------------------\n");
        printf("\tIntroduza o peso: ");
        scanf("%f", &peso);
        printf("\tIntroduza a altura: ");
        scanf("%f", &altura);
        printf("-------------------------------------------------\n");
        imc_loc = imc(peso, altura);
        // máximos e mínimos
        if (n_imc == 0){
            altura_min = altura;
            altura_max = altura;
            peso_min = peso;
            peso_max = peso;
            imc_min = imc_loc;
            imc_max = imc_loc;
        }else{
            if (altura < altura_min){
                altura_min = altura;
            }
            if (altura > altura_max){
                altura_max = altura;
            }
            if (peso < peso_min){
                peso_min = peso;
            }
            if (peso > peso_max){
                peso_max = peso;
            }
            if (imc_loc < imc_min){
                imc_min = imc_loc;
            }
            if (imc_loc > imc_max){
                imc_max = imc_loc;
            }
        }
        // totalizações
        altura_tot += altura;
        peso_tot += peso;
        imc_tot += imc_loc;
        printf("O seu IMC é de %.2f\n", imc_loc);
        if (imc_loc < 19){
            printf("Deve ganhar peso\n");
        }else if (imc_loc > 25){
            printf("Deve perder peso\n");
        }else{
            printf("Peso ótimo\n");
        }
        printf("-------------------------------------------------\n");
        do{
            printf("Calcular outra vez(s/n)?");
            scanf(" %c", &continuar);
        } while (continuar != 's' && continuar != 'n');
        printf("-------------------------------------------------\n");
        n_imc ++;
    } while (continuar == 's');
    system(CLEARCMD);
    printf("-------------------------------------------------\n");
    printf("Dados\n");
    printf("-------------------------------------------------\n");
    printf("Pesos\n");
    printf("\tMáximo - %.2f\n", peso_max);
    printf("\tMínimo - %.2f\n", peso_min);
    printf("\tMédia - %.2f\n", peso_tot / n_imc);
    printf("-------------------------------------------------\n");
    printf("Alturas\n");
    printf("\tMáxima - %.2f\n", altura_max);
    printf("\tMínima - %.2f\n", altura_min);
    printf("\tMédia - %.2f\n", altura_tot / n_imc);
    printf("-------------------------------------------------\n");
    printf("Indice de massa corporal\n");
    printf("\tMáximo - %.2f\n", imc_max);
    printf("\tMínimo - %.2f\n", imc_min);
    printf("\tMédia - %.2f\n", imc_tot / n_imc);
    printf("-------------------------------------------------\n");
    return 0;
}

float imc(float peso, float altura){
    return peso / (float)(altura * altura); 
}