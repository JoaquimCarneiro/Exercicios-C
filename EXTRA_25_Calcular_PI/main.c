/* EXERCÍCIO EXTRA 25 - Calcular PI
 * O valor aproximado de π pode ser calculado usando-se a série: 
 *      S = 1/1³ + 1/3³ + 1/5³ + ...
 * Fazer um algoritmo para calcular e escrever o valor de π com 51 termos tendo em conta que:
 *      π = ∛(s*32)
 * ISTO ESTÁ ERRADO
 * ---------------------------------------------
 * 
 * Calcular usando a série de Gregory-Leibniz (necessita de pelo menos 20k interações)
 * π = (4/1) - (4/3) + (4/5) - (4/7) + (4/9) - (4/11) + (4/13) - (4/15) ...
 * 
 * ---------------------------------------------
 * calcular usando a série de Nilakantha:
 * π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - 4/(12*13*14)
 * 
 * ---------------------------------------------
 * Calcular usando a série Madhava–Leibniz:
 * π = 4*(1 - 1/3 + 1/5 - 1/7 + 1/9)
 * 
 * */
#include <stdio.h>
#include <math.h>

double S(int interacoes);
double greg_leib(long int interacoes);
double nilakantha(int interacoes);
double madh_leib(long int interacoes);

int main(){
    printf("A Calcular PI utlizando a formula original\n\t PI = ");
    double s = S(51);
    printf("%.51f\n", cbrtf(s*32));
    printf("\nA Calcular PI utlizando a série de Gregory-Leibniz\n\t PI = ");
    printf("%.51f\n", greg_leib(1000000000)); // 10^9 interações == 8 digitos corretos
    
    printf("\nA Calcular PI utlizando a série de Nilakantha\n\t PI = ");
    printf("%.51f\n", nilakantha(100)); // a funcionar mal com interaçõe de valor muito altos 1k+

    printf("\nA Calcular PI utlizando a série de Madhava–Leibniz\n\t");
    printf("%.51f\n", madh_leib(1000000000)); // 10^9 interações == 8 digitos corretos (mais rápido)
    printf("\t%.51f\n", M_PI);
    return 0;
}

double S(int interacoes){
    double s = 0;
    int divisor = 1;
    for (int i = 0; i < interacoes; i++){
        s = s + (1 / powl(divisor, 3));
        //printf("%i - %i - %.51f\n", i, divisor, s);
        divisor = divisor +2;
    }
    return s;
}

double greg_leib(long int interacoes){
    double s = 0, divisor = 1;
    for (long int i = 0; i < interacoes; i++){
        //s = s + (1 / powf(divisor, 3));
        if (i % 2 != 0){
            s = s - (4/divisor);
        }else{
            s = s + (4/divisor);
        }
        //printf("%i - %i - %.51f\n", i, divisor, s);
        divisor = divisor +2;
    }
    return s;
}

double nilakantha(int interacoes){
    double s = 0;
    int divisor_ini = 2, divisor;
    for (int i = 0; i < interacoes; i++){
        //printf("\t%i\n", divisor_ini);
        //divisor = divisor_ini * ++divisor_ini * ++divisor_ini; // não sei porque não funciona
        divisor = divisor_ini * (divisor_ini + 1) * (divisor_ini + 2);
        //printf("\t%i\n", divisor);
        //printf("\t%i\n", divisor_ini);
        if (i % 2 != 0){
            s = s - ((float)4 / divisor);
        }else{
            s = s + ((float)4 / divisor);
        }
        //printf("%i - %.51f\n", i, s);
        divisor_ini += 2;
        
    }
    return s+3;
}

// π = 4*(1 - 1/3 + 1/5 - 1/7 + 1/9)
double madh_leib(long int interacoes){
    int divisor = 3;
    double serie = 1;
    for (long int i = 0; i < interacoes ; i++){
        if (i % 2 == 0){
            serie -=  ((double)1 / divisor);
        }else{
            serie +=  ((double)1 / divisor);
        }
        divisor = divisor + 2;
    }
    return serie * 4;
}