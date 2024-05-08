/*
 * Problema 21​
 * 1. Construa um algoritmo que verifique se um número introduzido pelo utilizador é ou não primo;​
 * 2. Mostre todos os números primos até um determinado número.​
 * numero primo: Um número primo é um número natural maior que 1 que não pode ser formado pela multiplicação 
 * de outros dois naturais menores:
 * 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113
*/
#include <stdio.h>

int is_prime(int num);

int main(){
    int num;
    printf("Numeros primos, introduza um número: ");
    scanf("%i", &num);
    if (is_prime(num)){
        printf("O número %i é primo\n\n", num);
    }else{
        printf("O número não é primo\n");
    }

    printf("Lista de números primos até %i:\n", num);
    for (int i = 1; i <= num; i++){
        if(is_prime(i)){
            printf("%i ", i);
        }
    }

    return 0;
}


int is_prime(int num){
    int prime_bool = 0;
    // Excepção: numero é igual a 2 a sua divisão por si proprio igual 0
    // se o numero a testar for 2 devolver "verdade" e sair
    if (num == 2){
        return 1;
    }
    // para todos os outros números acima de 2 e inferiores ao próprio
    for (int i = 2; i < num; i++){
        if ((num%i) != 0){
            prime_bool = 1;
        }else{ // numero é divisível por outro que não ele próprio ou 1
            return 0;
        }
    }
    return prime_bool;
}