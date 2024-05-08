/* Vetores EX 02 
 * Faça a leitura das pontuações que 5 juízes de uma 
 * determinada prova atribuíram a um atleta (valores
 * compreendidos entre 0 e 9 inclusive). Determine e
 * apresente com formato adequado, os seguintes valores:
 *      a) média obtida pelo atleta;
 *      b) a pior e a melhor pontuação;
 *      c) a percentagem de pontuações iguais ou superiores a 8 valores;
 *      d) supondo que a 1ª nota foi atribuída pelo juiz nº1 e
 *         assim sucessivamente determine os números dos
 *         juízes que atribuíram a melhor nota do atleta.
 * */

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "pt_PT.UTF-8");
    int n_atletas, juizes = 5, flag;
    printf("#######################################################################\n");
    printf("\tPontuações na competição\n");
    printf("#######################################################################\n");
    printf("Numero de atletas na competição: ");
    scanf("%i", &n_atletas);
    printf("-----------------------------------------------------------------------\n");
    float   notas_atletas[n_atletas][juizes],
            media, nota_menor, nota_maior, n_notas_altas,
            estatisica_atletas[n_atletas][4]; // os quatro valores da linha anterior

    for (int i = 0; i < n_atletas; i++){
        media = 0, nota_menor = 0, nota_maior = 0, n_notas_altas = 0;
        printf("\n-----------------------------------------------------------------------\n");
        printf("Atleta #%i\n", i+1);
        printf("-----------------------------------------------------------------------\n");
        for (int j = 0; j < juizes; j++){
            flag = 0;
            printf("\tPontução do Juiz #%i: ", j+1);
            do{
                if (flag > 0){
                    printf("\tValor inválido,\n\tintroduzir novamente: ");
                }
                scanf("%f", &notas_atletas[i][j]);
                flag ++;
            }while(notas_atletas[i][j] < 0 || notas_atletas[i][j] > 9);
            media += notas_atletas[i][j];
            if (j == 0){
                nota_menor = notas_atletas[i][j];
                nota_maior = notas_atletas[i][j];
            }else{
                if (notas_atletas[i][j] < nota_menor){
                    nota_menor = notas_atletas[i][j];
                }
                if (notas_atletas[i][j] > nota_maior){
                    nota_maior = notas_atletas[i][j];
                }
            }
            if (notas_atletas[i][j] >= 8){
                n_notas_altas += 1;
            }
        }
        printf("-----------------------------------------------------------------------\n");
        estatisica_atletas[i][0] = media / juizes;
        estatisica_atletas[i][1] = nota_menor;
        estatisica_atletas[i][2] = nota_maior;
        estatisica_atletas[i][3] = n_notas_altas;
    }

    printf("\n#######################################################################\n");
    printf("Resultados Finais.\n");
    printf("#######################################################################\n");
    int n_melhor_juizes, l_melhor_juizes[juizes], vencedor, n_vencedores = 0;
    for (int k = 0; k < n_atletas; k++){
        printf("\n-----------------------------------------------------------------------\n");
        printf("Atleta #%i\n", k+1);
        printf("-----------------------------------------------------------------------\n\n");
        printf("\tNotas: ");
        n_melhor_juizes = 0;
        for (int l = 0; l < juizes; l++){
            printf("%.2f", notas_atletas[k][l]);
            if(l+1 != juizes){
                printf(", ");
            }else{
                printf("\n");
            }
            if(notas_atletas[k][l] == estatisica_atletas[k][2]){
                n_melhor_juizes ++;
                l_melhor_juizes[l] = 1;
            }else{
                l_melhor_juizes[l] = 0;
            }
        }
        printf("\tMédia - %.2f\n", estatisica_atletas[k][0]);
        printf("\tNota Menor - %.2f\n", estatisica_atletas[k][1]);
        printf("\tNota Maior - %.2f\n", estatisica_atletas[k][2]);
        printf("\t%.0f Juize(s) atribuiram uma nota igual ou superior a 8 - %.2f%\n", estatisica_atletas[k][3], estatisica_atletas[k][3]/juizes*100);
        printf("\tA melhor nota foi atribuida por %i juiz(es):\n", n_melhor_juizes);
        for (int m = 0; m < juizes; m++){
            if(l_melhor_juizes[m]){
                printf("\t\tJuiz #%i\n", m+1);
            }
        }
        if (k == 0){
            vencedor = k;
            n_vencedores = 1;
        }else{
            if(estatisica_atletas[k][0] > estatisica_atletas[vencedor][0]){ // Caso em que existe só um vencedor
                vencedor = k;
                n_vencedores = 1;
            }else if(estatisica_atletas[k][0] == estatisica_atletas[vencedor][0]){ // Caso em que existe mas do que um vencedor
                vencedor = k;
                n_vencedores += 1;
            }
        }
    }
    if (n_vencedores > 1){
        printf("\n-----------------------------------------------------------------------\n");
        printf("\n\tEmpate técnico entre %i atletas com a nota %.2f:\n", n_vencedores, estatisica_atletas[vencedor][0]);
        for (int m = 0; m < n_atletas; m++){
            if(estatisica_atletas[m][0] == estatisica_atletas[vencedor][0]){
                printf("\t\tAtleta #%i\n", m+1);
            }
        }
        printf("\n-----------------------------------------------------------------------\n");
    }else{
        printf("\n-----------------------------------------------------------------------\n");
        printf("\n\tO atleta vencedor é o atleta #%i\n", vencedor + 1);
        printf("\n\t\t Classificação final - %.2f\n", estatisica_atletas[vencedor][0]);
        printf("\n-----------------------------------------------------------------------\n");
    }
    return 0;
}
