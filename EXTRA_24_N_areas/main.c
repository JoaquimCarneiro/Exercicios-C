#define _USE_MATH_DEFINES // VS CODE SUPIDITY...
/* EXERCÍCIO EXTRA 24 - Calcular N areas 
 * Elabore um algoritmo que possibilite ao utilizador
 * calcular N vezes:​
 *   Área de triângulos (Base x Altura/2)​ ou
 *   Área de Quadriláteros (Lado x Lado)​ ou
 *   Área de Círculos (π x raio²)​ ou
 *   Hipotenusa do triângulo​
 * (Hipotenusa² = cateto² + cateto²)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#ifdef _WIN32
    #define CLEARCMD "cls"
#else
    #define CLEARCMD "clear"
#endif

// configuração de menus
#define LARGURA 96
#define UI_CHAR '#'

// configuração de outputs
#define OUT_ITEM_P_PAGE 5

/* HEADER - UI - coisas da interface de utilizador*/
void flushBuffer();
void pausar();
void separador(int largura, char caractere, int espacoAntes, int espacoDepois);
void titulo(int largura, char caractere, char *titulo, int centrar, int espacoAntes, int espacoDepois);
void sub_titulo(int largura, char caractere, char *titulo, int espacoAntes, int espacoDepois);
void menu(int largura, char caractere, char *titulo, int espacoAntes, int espacoDepois);

int main(){
    setlocale(LC_ALL, "pt_PT.UTF-8");
    system(CLEARCMD);
    // variáveis iniciais
    // m_calculos - numero de cálculos a realizar
    // op - operação escolhida pelo utilizador
    // flag - variável de controle para verificação de dados pelo utilizador e mensagem de erro
    int n_calculos, flag = 0, op;
    // Os cálculos dependem de uma ou duas variáveis para realizar os cálculos
    float operandoA, operandoB, calculo;
    titulo(LARGURA, UI_CHAR, "Cálculos geométricos", 1, 0, 1);
    // verificar se o utilizador inseriu um valor superior a zero
    // só verifica se o numero de escolhas é superior a zero
    // um caratere pode quebrar (quebra) o programa
    do{
        if (flag > 0){
            printf("Valor inválido\n");
        }
        printf("Quantas operações deseja realizar: ");
        scanf("%i", &n_calculos);
        flag ++;
    } while (n_calculos <= 0);
    // arrays para gerir cáculos e os seus valores (arrays estão inter-relacionados)
    char figuras[4][50] = {"Triangulo", "Quadrilatero", "Circulo", "Hipotenusa"}; // 50 talvez seja demais
    int tipo_operacao[n_calculos], qnt_areas[4] = {0, 0, 0, 0}, i; // i defenido fora do for para ser usado mais à frente
    float valor_operacao[n_calculos], total_areas[4] = {0, 0, 0, 0};
    
    // para string operação n de x (definidas fora do loop)
    char cont_operacao[100], str_n_calc[10], str_contador[10];
    
    for (i = 0; i < n_calculos; i++){
        system(CLEARCMD);
        titulo(LARGURA, UI_CHAR, "Cálculos geométricos", 1, 0, 1);
        menu(LARGURA, UI_CHAR, "Menu principal", 0, 0);
        flag = 0; // reset à flag
        do{
            if (flag > 0){
                printf("Operação inválida\n");
            }
            printf("escolha a operação: ");
            scanf("%i", &op);
            flag ++;
        } while (op < 0 || op >4);
        // Execução de operações
        // se a opção for 0 abortar o ciclo
        if (op == 0){
            // printf("A abortar...\n");
            break;
        }else{
            tipo_operacao[i] = op;
            system(CLEARCMD);
            titulo(LARGURA, UI_CHAR, "Cálculos geométricos", 1, 0, 1);
            // concatenação da string "operação n de x"
            strcpy(cont_operacao, "Operação "); // forçar reset ao array
            sprintf(str_contador, "%i de %i", i+1, n_calculos);
            strcat(cont_operacao, str_contador);
            //
            sub_titulo(LARGURA, UI_CHAR, cont_operacao, 0, 1);
            separador(LARGURA, UI_CHAR, 0, 1);
            switch (op){
                case 1:
                    titulo(LARGURA, UI_CHAR, "Calcular área do triangulo", 0, 1, 2);
                    printf("Introduza a base: ");
                    scanf("%f", &operandoA);
                    printf("Introduza a altura: ");
                    scanf("%f", &operandoB);
                    calculo = operandoA * operandoB / 2;
                    qnt_areas[op-1] ++;
                    total_areas[op-1] += calculo;
                    separador(LARGURA, '-', 0, 1);
                    printf("O triangulo tem a àrea de %.2f\n", calculo);
                    separador(LARGURA, UI_CHAR, 1, 1);
                    pausar();
                    flushBuffer(); //efeito secudário do pausar
                    break;
                case 2:
                    titulo(LARGURA, UI_CHAR, "Calcular área do Quadrilátero", 0, 1, 2);
                    printf("Introduza o primeiro lado: ");
                    scanf("%f", &operandoA);
                    printf("Introduza o segundo lado: ");
                    scanf("%f", &operandoB);
                    calculo = operandoA * operandoB;
                    qnt_areas[op-1] ++;
                    total_areas[op-1] += calculo;
                    separador(LARGURA, '-', 0, 1);
                    printf("O Quadrilátero tem a àrea de %.2f\n", calculo);
                    separador(LARGURA, UI_CHAR, 1, 1);
                    pausar();
                    flushBuffer(); //efeito secudário do pausar
                    break;
                case 3:
                    titulo(LARGURA, UI_CHAR, "Calcular área do Círculo", 0, 1, 2);
                    printf("Introduza o raio: ");
                    scanf("%f", &operandoA);
                    calculo = M_PI * powf(operandoA, 2);
                    qnt_areas[op-1] ++;
                    total_areas[op-1] += calculo;
                    separador(LARGURA, '-', 0, 1);
                    printf("O Círculo tem a àrea de %.2f\n", calculo);
                    separador(LARGURA, UI_CHAR, 1, 1);
                    pausar();
                    flushBuffer(); //efeito secudário do pausar
                    break;
                case 4:
                    titulo(LARGURA, UI_CHAR, "Calcular Hipotenusa", 0, 1, 2);
                    printf("Introduza o primeiro lado: ");
                    scanf("%f", &operandoA);
                    printf("Introduza o segundo lado: ");
                    scanf("%f", &operandoB);
                    calculo = sqrtf(powf(operandoA, 2) + powf(operandoB, 2));
                    qnt_areas[op-1] ++;
                    total_areas[op-1] += calculo;
                    separador(LARGURA, '-', 0, 1);
                    printf("O Hipotenusa tem o comprimento de %.2f\n", calculo);
                    separador(LARGURA, UI_CHAR, 1, 1);
                    pausar();
                    flushBuffer(); //efeito secudário do pausar
                    break;
            }
            valor_operacao[i] = calculo;
        }
    }

    // OUTPUT DE DADOS
    system(CLEARCMD);
    titulo(LARGURA, UI_CHAR, "Cálculos geométricos", 1, 0, 2);
    // printf("%i\n", i);
    if (i == 0 && op == 0){
        printf("Operações abortadas, nenhum dado inserido!\n");
        separador(LARGURA, UI_CHAR, 1, 1);
    }else{
        if (op == 0){
            flushBuffer(); // necessário quando a opção selecionada é abortar
        }
        /* Loop que percorre os arrays para produzir o output:
         * figuras, tipo_operacao, valo_operacao
         * */
        char nome_operacao[50];
        for (int j = 0; j < i; j++){
            // construção de frase de output
            if (tipo_operacao[j] != 4){
                strcpy(nome_operacao, "A area do ");
            }else{
                strcpy(nome_operacao, "O valor da ");
            }
            printf("Operação #%i de %i:\n\t%s%s calculada foi de %.2f\n", j+1, n_calculos, nome_operacao, figuras[tipo_operacao[j]-1], valor_operacao[j]);
            //parar quando os dados de output sejam muitos
            if ((j+1) % OUT_ITEM_P_PAGE == 0 && (j+1) != n_calculos){
                separador(LARGURA, UI_CHAR, 1, 1);
                pausar();
                // Limpar ecra e re-escrever título
                system(CLEARCMD);
                titulo(LARGURA, UI_CHAR, "Cálculos geométricos", 1, 0, 2);
            }
        }
        if (op == 0){
            separador(LARGURA, UI_CHAR, 1, 2);
            printf("Operações abortadas, nenhum dado adicional inserido!\n");
        }
        separador(LARGURA, UI_CHAR, 1, 1);
        pausar();
        // Totais
        system(CLEARCMD);
        titulo(LARGURA, UI_CHAR, "Totais", 1, 0, 2);
        for (int k = 0; k < 4; k++){
            if (k == 4){
                printf("Foram calculadas %i %s(s)", qnt_areas[k], figuras[k]);
                if (qnt_areas[k] > 0){
                    printf(", prefazendo um total de %.2f", total_areas[k]);
                }
                printf("\n");
            }else{
                printf("Foram calculadas %i area(s) de %s", qnt_areas[k], figuras[k]);
                if (qnt_areas[k] > 0){
                    printf(", prefazendo um total de %.2f", total_areas[k]);
                }
                printf("\n");
            }
        }
        separador(LARGURA, UI_CHAR, 1, 1);
        
    }
    return 0;
}

void flushBuffer(){
	int ch;
	while((ch = getchar()) != '\n' && ch != EOF);
}

void pausar(){
    printf("Prima ENTER para continuar ");
    getchar(); //
    // pode ser necessário fazer flushbuffer() após executar esta função
}

void separador(int largura, char caractere, int espacoAntes, int espacoDepois){
    if (espacoAntes > 0){
        for (int j = 0; j < espacoAntes; j++){
            printf("\n");
        }
    }
    for (int i = 0; i < largura; i++){
        printf("%c", caractere);
    }
    if (espacoDepois > 0){
        for (int k = 0; k < espacoDepois; k++){
            printf("\n");
        }
    }
}

void titulo(int largura, char caractere, char *titulo, int centrar, int espacoAntes, int espacoDepois){
    int titulo_size = strlen(titulo);
    int espaco = (largura - titulo_size) / 2;
    separador(largura, caractere, espacoAntes, 1);
    if (centrar == 0){
        printf("%s", titulo);
    }else{
        for (int i = 0; i < espaco; i++){
            printf(" ");
        }
        printf("%s", titulo);
    }
    separador(largura, caractere, 1, espacoDepois);
}

void sub_titulo(int largura, char caractere, char *titulo, int espacoAntes, int espacoDepois){
    int titulo_size = strlen(titulo);
    int tab_space = (largura - titulo_size); // largura total - largura titulo 
    int espaco =  tab_space / 2;
    if (espacoAntes > 0){
        for (int k = 0; k < espacoAntes; k++){
            printf("\n");
        }
    }
    if(tab_space % 2 != 0){
        printf("%c", caractere);//espaço extra
    }
    for (int i = 0; i < espaco; i++){
        printf("%c", caractere);
    }
    printf(" %s ", titulo);
    for (int j = 0; j < espaco; j++){
        printf("%c", caractere);
    }
    if (espacoDepois > 0){
        for (int l = 0; l < espacoDepois; l++){
            printf("\n");
        }
    }
}

void menu(int largura, char caractere, char *titulo, int espacoAntes, int espacoDepois){
    sub_titulo(largura-2, caractere, titulo, 0, 2); // por razão que não estou a detectar estão a ser inseriddos 2 caracteres a mais
    printf( "\t1 - Área do triangulo\n"
            "\t2 - Área do Quadrilatero\n"
            "\t3 - Área do círculo\n"
            "\t4 - Hipotenusa do triangulo\n"
            "\t0 - Abortar\n"
            );
    separador(largura, caractere, 1, 1);
}