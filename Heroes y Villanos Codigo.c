#include <stdio.h>
#include <string.h>
#define VIDA_INICIO 100

struct Personaje {
    char nombre[100];
    char presentacion[400];
    int vida;
    int danio[3];
    int defensa[3];
};

struct Personaje crearPersonaje (char nombre[], char presentacion[], int vida, int danio[], int defensa[]){
    struct Personaje nuevoPersonaje;
    strcpy(nuevoPersonaje.nombre, nombre);
    strcpy(nuevoPersonaje.presentacion, presentacion);
    nuevoPersonaje.vida = VIDA_INICIO;
    nuevoPersonaje.danio[0]= 20;
    nuevoPersonaje.danio[1]= 50;
    nuevoPersonaje.danio[2]= 80;
    nuevoPersonaje.defensa[0]= 30;
    nuevoPersonaje.defensa[1]= 10;
    nuevoPersonaje.defensa[2]= 40;
    return nuevoPersonaje;
}
void imprimirPersonaje(struct Personaje p){
    printf("Nombre: %s\n", p.nombre);
    printf("Descripcion: %s\n", p.presentacion);
    printf("Vida Inicial: %d\n", p.vida);
    printf("Daño que puede hacer: %d, %d y %d\n", p.danio[0], p.danio[1], p.danio[2]);
    printf("Defensa que tiene: %d, %d y %d\n", p.defensa[0], p.defensa[1], p.defensa[2]);
}
int main() {
    int danioAlmighty[3] = {30, 40, 50};
    int defensaAlmighty[3] = {50, 60, 70};
    int danioEvilBunny[3] = {25, 35, 45};
    int defensaEvilBunny[3] = {55, 65, 75};

    struct Personaje Almighty = crearPersonaje("Almighty", "Héroe y cantante que combate a Evil Bunny, quien quiere controlar el mundo con ideas obscenas", VIDA_INICIO, danioAlmighty, defensaAlmighty);
    struct Personaje EvilBunny = crearPersonaje("Evil Bunny", "Villano que quiere controlar el mundo con sus ideas obscenas", VIDA_INICIO, danioEvilBunny, defensaEvilBunny);
    imprimirPersonaje(Almighty);
    imprimirPersonaje(EvilBunny);
    return 0;
}
