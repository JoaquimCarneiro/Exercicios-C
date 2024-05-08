/* Vetores EX1 - 10 Numeros inteiros
 * Faça um programa que inclua:
 * a) Uma função que faça a leitura de 10 valores (inteiros), guardando–os num vetor;
 * b) Uma função que retorne a diferença entre o maior e o menor valor do vetor;
 * c) Uma função que devolva o número de valores pares e ímpares do vetor;
 * */

#include <stdio.h>

void add_to_arr(int n, int arr[n]);
void listar_arr(int n, int arr[n]);
int dif_maior_menor(int n, int arr[n]);
void pares_impares(int n, int arr[n], int *par, int *impar);

int main(){
    int n_items = 10, lista[n_items], dif_max_min, n_par = 0, n_impar = 0;
    printf("--------------------------------------------------------\n");
    printf("Operações com arrays\n");
    printf("--------------------------------------------------------\n");
    add_to_arr(n_items, lista);
    printf("--------------------------------------------------------\n");
    printf("Listar numeros introduzidos:\n");
    listar_arr(n_items, lista);
    printf("--------------------------------------------------------\n");
    printf("Maior e menor numero:\n");
    dif_max_min = dif_maior_menor(n_items, lista);
    printf("A diferença entre o numero maior e o menor é %i.\n", dif_max_min);
    printf("--------------------------------------------------------\n");
    pares_impares(n_items, lista, &n_par, &n_impar);
    printf("Foram introduzidos %i numero(s) par e %i numero(s) impar\n", n_par, n_impar);
    
    return 0;
}

void add_to_arr(int n, int arr[n]){
    printf("Introduza %i numeros inteiros\n", n);
    for (int i = 0; i < n; i++){
        printf("Numero #%i: ", i+1);
        scanf("%i", &arr[i]);
    }
}

void listar_arr(int n, int arr[n]){
    for (int i = 0; i < n; i++){
        printf("%i", arr[i]);
        if(i != n - 1){
            printf(", ");
        }
    }
    printf("\n");
}

int dif_maior_menor(int n, int arr[n]){
    int maior, menor;
    for (int i = 0; i < n; i++){
        if(i == 0){
            maior = arr[i];
            menor = arr[i];
        }else{
            if(arr[i] < menor){
                menor = arr[i];
            }
            if(arr[i] > maior){
                maior = arr[i];
            }
        }
    }
    printf( "Valor Maior - %i\n"
            "Valor Menor - %i\n", maior, menor);
    return maior - menor;
}

void pares_impares(int n, int arr[n], int *par, int *impar){
    for (int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            *par += 1;
        }else{
            *impar += 1;
        }
    }
}