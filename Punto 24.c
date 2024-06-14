#include <stdio.h>
#define PI 3.1415926535897932384626433832795

int main()
{
    float r, a, vol, h;
    printf("Benvenuti in questo programma in cui si determina l'area e il volume di un cilindro con il raggio (r) e l'altezza (h) \n");
    scanf("%f", &r);
    scanf("%f",&h);
    vol=PI*r*r*h;
    a=PI*2*r*(h+r);
    printf("Il tuo volume e:%f, e la sua area è: %f", vol, a);
    return 0;
}
