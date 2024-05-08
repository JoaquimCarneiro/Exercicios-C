/* Calcular raiz n de x*/
#include <stdio.h>
#include <math.h>

int n_root(int input, int n){
  return round(pow(input, 1./n));
}
float n_rootf(float input, float n){
  return powf(input, 1./n);
}
double n_rootd(double input, double n){
  return powl(input, 1./n);
}
int main(){
    printf("%.lf\n", round(pow(32, 1.0/5)));// uai? necessita de %f, %lf ou de %li??
    printf("%i\n", n_root(32,5));
    printf("%.12f\n", n_rootf(64,5));
    printf("%.12lf\n", n_rootd(64,5));
    return 0;
}
