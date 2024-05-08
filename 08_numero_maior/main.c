/* 
 * Problema 8​
 * Ler quatro números e determinar qual o maior deles.​
 * Extra:
 *  - Quantidade de numeros na lista é pedida ao utilizador
 *  - Ordenação crescente da lista
 * */

#include <stdio.h>

int main(){
    int qtd, maior;
    printf( "Determinar o maior numero num conjunto de numeros.\n"
            "\tQuantos numero tem  o conjunto: ");
    scanf("%i", &qtd);

    // se o utilizador introduzir um numero <= 1, não faz sentido e termina o programa
    if(qtd <= 1){
        printf("Grupo de numeros inválido\n");
        return 1;
    }else{
        int numeros[qtd];
        printf("Insira os %i Numeros\n", qtd);
        for (int i = 0; i < qtd; i++){
            printf("\tNumero %i: ", i+1);
            scanf("%i", &numeros[i]);
        }
        
        for (int j = 0; j < qtd; j++){
            if (j == 0){
                maior = numeros[0];
            }else if (numeros[j] > maior){
                maior = numeros[j];
            }        
        }
        printf("\nO maior numero é o %i\n", maior);

        // EXTRA: Ordenação crescente do array
        int temp = 0, flag;
        do{
            flag = 0;
            for (int k = 0; k < qtd; k++){
                if(k < qtd -1){
                    if (numeros[k] > numeros[k+1]){
                        temp = numeros[k+1];
                        numeros[k+1] = numeros[k];
                        numeros[k] = temp;
                        flag ++;
                    }
                }
            }
        } while (flag != 0);

        for (int l = 0; l < qtd; l++){
            printf("%i ", numeros[l]);
        }
    }
    return 0;
}
