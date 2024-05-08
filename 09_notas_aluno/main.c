/*
 * Problema 9
 * Ler as notas de um aluno às disciplinas de 
 * Matemática, Português, Inglês e Geografia e calcular a média. ​
 * Em  função  da  média  mostrar  uma  mensagem  com  o  conteúdo  “APROVADO”  ou “REPROVADO”.​ 
 * O aluno terá positiva se a nota for igual ou superior a 9,5 valores. 
 * EXTRA
 * usa um array de strings para guardar o nome das disciplinas (char disciplinas[][])
 * usa um array de floats para guardar as notas de cada disciplina (notas[]) em correspondencia com o array de disciplinas
 * (provavelmente seria melhor usar struts)
 */

#include <stdio.h>

int main()
{
    int n_disciplinas = 4;
    char disciplinas[][20] = {"Matemática", "Português", "Inglês", "Geografia"};
    float notas[n_disciplinas], nota_local = 0, nota_total = 0, media;
    for (int i = 0; i < n_disciplinas; i++){
        printf("Introduza a nota para a disciplina de %s: ", disciplinas[i]);
        scanf("%f", &nota_local);
        notas[i] = nota_local; // extra para guardar a nota por disciplina
        nota_total += nota_local;
    }
    media = nota_total/n_disciplinas;
    printf("A média do aluno é de: %.2f\n"
            "Notas das diciplinas:\n", media);
    /* descrever as notas (extra)*/
    for (int i = 0; i < n_disciplinas; i++){
        printf("\t%s: %.2f\n", disciplinas[i], notas[i]);
    }
    if(media >= 9.5){
        printf("APROVADO");
    }else{
        printf("REPROVADO");
    }
    return 0;
}
