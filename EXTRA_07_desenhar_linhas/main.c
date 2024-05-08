/* EXERCÍCIO EXTRA 7 - Desenhar linhas
 * Escreva um programa que produza o seguinte output
 *      ***​
 * 
 *      *****​
 * 
 *      *******​
 * 
 *      *****​
 * 
 *      ***
 * ​, recorrendo a:​
 * 1 - Três funções distintas​
 * 2 - Apenas uma função,​
 * 3 - Em vez do carater ‘*’, imprimir um carater à escolha do utilizador.
 * */

#include <stdio.h>

#ifdef _WIN32
    #define CLEARCMD "cls"
#else
    #define CLEARCMD "clear"
#endif

void linhas(int size, char caractere);
void incrementar_linha(int min, int max, int incremento, char caractere);
void decrementar_linha(int min, int max, int incremento, char caractere);
void tudo_em_um(int min, int max, int incremento, char caractere);

void flushBuffer();
void pausar();

int main(){
    int min = 3, max = 7, incremento = 2;
    char caractere = '*';
    int escolha;
    do{
        system(CLEARCMD);
        printf( "[ MENU ]\n"
                "-------------------------------------------------\n"
                "\t1 - Usando 3 funções distintas\n"
                "\t2 - Usando apenas uma função\n"
                "\t3 - Utilizador pode escolher caractere\n"
                "\t0 - Sair\n"
                "-------------------------------------------------\n");
        do{
            printf("Escolha a opção: ");
            scanf("%i", &escolha);
        } while (escolha < 0 || escolha > 3);
        
        flushBuffer();
        
        switch (escolha){
            case 1:
                printf("-------------------------------------------------\n\n");
                incrementar_linha(min, max, incremento, caractere);
                decrementar_linha(min, max, incremento, caractere);
                pausar();
                break;
            case 2:
                printf("-------------------------------------------------\n\n");
                tudo_em_um(min, max, incremento, caractere);
                pausar();
                break;
            case 3:
                printf("-------------------------------------------------\n");
                printf("Escolha um caractere: ");
                scanf(" %c", &caractere);
                printf("-------------------------------------------------\n\n");
                tudo_em_um(min, max, incremento, caractere);
                pausar();
                flushBuffer();
                break;
            default:
                printf("A sair...\n");
                break;
        }
    } while (escolha != 0);
    return 0;
}

/* funções para satifazer os casos pedidos 
 * foram pensadas para serem dinâmicas mas não foram feitos testes
 * só foi testado o caso em qeu o valo minimo é 3, o máximo é 7 e o incremento é 2 */
void linhas(int size, char caractere){
    int i = 0;
    while (i < size){
        printf("%c", caractere);
        i++;
    }
    printf("\n");
}

void incrementar_linha(int min, int max, int incremento, char caractere){
    while (min <= max){
        linhas(min, caractere);
        printf("\n");
        min += incremento;
    }
}

void decrementar_linha(int min, int max, int incremento, char caractere){
    while (min < max){
        max -= incremento;
        linhas(max, caractere);
        printf("\n");
    }
}

/* esta função podia ter sido feita com dois pares de loops,
 * um crescente e outro decrescente,
 * no entanto achei mais interessante usar só um par e usar
 * condicionais para realizar o incremento ou decremento */
void tudo_em_um(int min, int max, int incremento, char caractere){
    int i = 0, flag = 0, static_min = min;
    while (min > 0){
        while (i < min){
            printf("%c", caractere);
            i++;
        }
        printf("\n\n");
        if (flag == 0){
            min += incremento;
        }else{
            if((min - incremento) >= static_min){
                min -= incremento;
            }else{
                min = 0;
            }
        }
        if (min >= max){
            flag++;
        }
        i = 0;
    }
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