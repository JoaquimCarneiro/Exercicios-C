/*
 * Problema 10
 * Pretende-se calcular as ajudas de custo a pagar aos funcionários de uma empresa
 * que tenham de se deslocar  em  viatura  própria  para  serviço  da  empresa.
 * O  valor  é  em  função  da  distância percorrida  e  do  valor  por  quilómetro
 * que  por  sua  vez,  é  função  da  motorização  do  veículo (cilindrada do motor),
 * como se indica a seguir:​
 *      Motor de cilindrada inferior a 2000 cm³ será financiado a 0.2€ por km.​
 *      Motor de cilindrada superior ou igual a 2000 cm³ será financiado a 0.3 € por km.​
 * Ajuda de custo = valor por quilometro * distância percorrida.
 */

#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    float kilometros, cilindrada, rate, ajuda;
    printf("Cilindrada do veículo: ");
    scanf("%f", &cilindrada);
    printf("Kilómetros percorridos: ");
    scanf("%f", &kilometros);
    if (cilindrada < 2000){
        rate = 0.2;
    }else{
        rate = 0.3;
    }
    ajuda = kilometros * rate;
    printf("A ajuda de custos é de %.2f €", ajuda);

    return 0;
}
