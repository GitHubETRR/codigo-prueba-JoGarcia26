include <stdio.h>
#include <math.h>

float const pi=3.14;
int main(void){
    int op;
    do{
        printf("Pon 1 si es un circulo o pon 2 si es un cuadrado \n");
        scanf("%d", &op);
        if(op == 2){
            float Cua_1, Cua_2;
            printf("A continuacion introducan un lado: \n");
            scanf("%f", &Cua_1);
            printf("A continuacion ingrese el otro lado: \n");
            scanf("%f", &Cua_2);
            printf("Sus lados ingresados son:\n %f %f \n", Cua_1, Cua_2);
            float area= Cua_1*Cua_2;
            float per= Cua_1*2+Cua_2*2;
            printf("Su area es: \n %f \n", area);
            printf("Su perimetro es: \n %f", per);
        }else if(op==1){
            float circ;
            printf("A continuacion, ingrese el radio\n");
            scanf("%f", &circ);
            float per_circ=2* pi* circ;
            printf("Su perimetro es: \n");
            printf("%lf \n", per_circ);
            float area_circ= 3.14* pow(circ, 2);
            printf("Su area es:\n");
            printf("%lf \n", area_circ);
        }
        }while ((op==1 && op==2));
    printf("Muchas gracias por usar este programa, que tenga buen dia :)");
    return 0;
}
