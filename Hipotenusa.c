#include <stdio.h>
#include <math.h>

int main()
{
    float cateto_a, cateto_b;
    printf("Inserte los valores de sus catetos \n");
    printf("Cateto A: \n");
    scanf("%f", &cateto_a);
    printf("Cateto B:\n");
    scanf("%f", &cateto_b);
    double hip = pow(cateto_a, 2)+ pow(cateto_b, 2);
    printf("Su hipotenusa es: %lf", hip);
    return 0;
}
