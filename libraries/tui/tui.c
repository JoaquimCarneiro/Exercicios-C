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

void menu(int largura,
	  char caractere,
	  char *titulo,
	  int option_size, // not really needed
	  int n_options,
	  char options[n_options][option_size],
	  int espacoAntes,
	 int espacoDepois){
    sub_titulo(largura-2, caractere, titulo, 0, 2); // por razão que não estou a detectar estão a ser inseriddos 2 caracteres a mais
    for(int i = 0; i < n_options; i++){
	printf( "\t%i - %s\n", i + 1, options[i]);
    }
    printf("\t0 - Abortar\n");
    separador(largura, caractere, 1, 1);
}
