/* Dimensinamento de tubagem em sistema pneumático 
 * log
 * versão 0.1
 *      - construção de formula base
 *      - Conversão para polegadas
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./lib/ui.h"

#define POLEGADA 25.4

// configuração de menus
#define LARGURA 96
#define UI_CHAR '#'
#define UI_CHAR_SEC '-'

double diametro_tubo(double caudal, double comprimento, double delta_pressao, double pressao);

int main(){
    double len_tubo, diametro, caudal, delta, pressao;
    int n_atuadores;
    system(CLEARCMD);
    titulo(LARGURA, UI_CHAR, "Dimensionamento de Tubagem Pneumática", 1, 0, 1);
    separador(LARGURA, UI_CHAR_SEC, 0, 1);
    sub_titulo(LARGURA, ' ', "Determinação de caudal",0,1);
    separador(LARGURA, UI_CHAR_SEC, 0, 1);
    printf("Inserir quantidade de atuadores: ");
    scanf("%i", &n_atuadores);
    separador(LARGURA, UI_CHAR_SEC, 0, 1);
    char nome_atuadores[n_atuadores][50];
    float consumo_total = 0, consumo_atuadores[n_atuadores];
    int atuador = 0, flag = 0;
    
    do{
        flushBuffer();
        separador(LARGURA, UI_CHAR_SEC, 0, 1);
        printf("Atuador #%i:\n", atuador +1);
        separador(LARGURA, UI_CHAR_SEC, 0, 1);
        printf("Introduzir Nome: ");
        fgets(nome_atuadores[atuador], 50, stdin);
        //scanf("%s", &nome_atuadores[atuador]);
        printf("Introduzir consumo: ");
        scanf("%f", &consumo_atuadores[atuador]);
        separador(LARGURA, UI_CHAR_SEC, 0, 1);
        atuador ++;
    } while (atuador < n_atuadores);
    
    /* double diametro = diametro_tubo(480, 300, 0.3, 9);
    printf("Diametro(mm) - %.6f mm\n", diametro);
    printf("Diametro(Pol) - %.6f pol\n", diametro/POLEGADA); */
    return 0;
}

double diametro_tubo(double caudal, double comprimento, double delta_pressao, double pressao){
    // "constantes"
    double const_dividendo = 1.663785, const_exp = 1.85;
    int const_decimal = 10, exp_divisor = 3;
    // Variaveis
    double radicando, diametro;
    int indice = 5;

    radicando = (const_dividendo * powf(caudal, const_exp) * comprimento) / (delta_pressao * pressao * powf(const_decimal, exp_divisor));
    diametro = const_decimal * powl(radicando, 1.0/indice);
    return diametro;
}
