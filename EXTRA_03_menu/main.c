/*
 * Exercício 3
 * Escreva um programa que apresente um menu com as opções
 * Clientes, Formnecedores e Sair
 * O programa deve apresentar a opção escolhida pelo utilizador até que o utilizador deseje sair.
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    char opcao;
    printf( "#################### MENU ####################\n"
            "\tC - Clientes\n"
            "\tF - Fornecedores\n"
            "\tS - Sair\n"
            "##############################################\n"
            );
    do{
        printf("Escolher opção: ");
        scanf(" %c", &opcao);
        opcao = tolower(opcao);
    } while (opcao != 'c' && opcao != 'f' && opcao != 's');

    switch (opcao){
        case 'c':
            printf("#################### Area de clientes ####################\n");
            break;
        case 'f':
            printf("#################### Area de Fornecedores ####################\n");
            break;
        case 's':
            printf("A sair...");
            break;            
    }
    return 0;
}

