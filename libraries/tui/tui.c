#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void flushBuffer(){
	int ch;
	while((ch = getchar()) != '\n' && ch != EOF);
}

void pausar(){
    printf("Prima ENTER para continuar ");
    getchar(); //
    // pode ser necessário fazer flushbuffer() após executar esta função,
    // visto o getchar deixar um \n como lixo
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

void menu(
            int largura, // largura do menu
            char caractere, // caractere principal construir o menu
            char caractere_sec, // caractere secundário para separadores internos
            char *titulo, // titulo do menu
            int option_size, // necessário para o array options
            int n_options, // numero de opções
            char options[n_options][option_size], // array de opções a apresentar ao utilizador
            int option_type, // se a opção é um numero ou um caractere 0 - numero !0 - alfa
            char exit_option, // char para a opção de saida
            char *exit_text, // texto da opção de saida
            int espacoAntes, // espaços antes do menu
            int espacoDepois // espaços depois do menu
        ){
    int alfa_num;
    if(option_type == 0){
        alfa_num = 49; // ASCII para 1
    }else{
        alfa_num = 65; // ASCII para A
    }
    sub_titulo(largura-2, caractere, titulo, 0, 2); // por razão que não estou a detectar estão a ser inseriddos 2 caracteres a mais
    separador(largura, caractere_sec, 0, 1);
    for(int i = 0; i < n_options; i++){
	    printf( "\t%c - %s\n", i + alfa_num, options[i]); // items do menu
    }
    separador(largura, caractere_sec, 0, 1);
    printf("\t%c - %s\n", exit_option, exit_text); // exit option
    separador(largura, caractere_sec, 0, 1);
    separador(largura, caractere, 1, 1);
}
