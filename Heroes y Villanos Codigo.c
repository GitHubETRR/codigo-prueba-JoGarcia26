#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CHAR 300

typedef struct {
    char nombre[MAX_CHAR];
    char presentacion[MAX_CHAR];
    int vida;
    char poderes[3][MAX_CHAR];
    char defensas[3][MAX_CHAR];
    int valores_poderes[3];
    int valores_defensas[3];
    int cooldown_poderes[3];
    int cooldown_defensas[3];
} Personaje;

typedef struct {
    int daño_infringido;
    int daño_recibido;
} ResultadoAtaque;

ResultadoAtaque atacar(Personaje *atacante, Personaje *defensor) {
    int eleccion_ataque, eleccion_defensa;
    ResultadoAtaque resultado = {0, 0};

    printf("%s, ¡es tu turno! Elige un ataque:\n", atacante->nombre);
    for (int i = 0; i < 3; i++) {
        if (atacante->cooldown_poderes[i] > 0) {
            printf("%d. %s (Bloqueado por %d turnos)\n", i + 1, atacante->poderes[i], atacante->cooldown_poderes[i]);
        } else {
            printf("%d. %s (Daño: %d)\n", i + 1, atacante->poderes[i], atacante->valores_poderes[i]);
        }
    }
    do {
        scanf("%d", &eleccion_ataque);
        eleccion_ataque--;
    } while (atacante->cooldown_poderes[eleccion_ataque] > 0);

    printf("%s, elige una defensa:\n", defensor->nombre);
    for (int i = 0; i < 3; i++) {
        if (defensor->cooldown_defensas[i] > 0) {
            printf("%d. %s (Bloqueada por %d turnos)\n", i + 1, defensor->defensas[i], defensor->cooldown_defensas[i]);
        } else {
            printf("%d. %s (Defensa: %d)\n", i + 1, defensor->defensas[i], defensor->valores_defensas[i]);
        }
    }
    do {
        scanf("%d", &eleccion_defensa);
        eleccion_defensa--;
    } while (defensor->cooldown_defensas[eleccion_defensa] > 0);

    int daño = atacante->valores_poderes[eleccion_ataque] - defensor->valores_defensas[eleccion_defensa];
    if (daño < 0) daño = 0;

    int critico = rand() % 100 < 20; 
    if (critico) {
        printf("¡Increíble! ¡Ataque crítico! %s inflige daño aumentado.\n", atacante->nombre);
        daño = (int)(daño * 1.5);
    }
    
    defensor->vida -= daño;
    if (defensor->vida < 0) defensor->vida = 0;
    resultado.daño_infringido = daño;
    resultado.daño_recibido = daño;
    printf("%s usa %s contra %s que utiliza %s. Daño causado: %d.\n",
           atacante->nombre, atacante->poderes[eleccion_ataque], defensor->nombre,
           defensor->defensas[eleccion_defensa], daño);
    atacante->cooldown_poderes[eleccion_ataque] = 3; 
    defensor->cooldown_defensas[eleccion_defensa] = 2; 
    return resultado;
}

Personaje actualizarCooldowns(Personaje p) {
    for (int i = 0; i < 3; i++) {
        if (p.cooldown_poderes[i] > 0) p.cooldown_poderes[i]--;
        if (p.cooldown_defensas[i] > 0) p.cooldown_defensas[i]--;
 }
    return p;
}

int Derrotado(Personaje p) {
    return p.vida <= 0;
}

void mostrarEstadisticas(Personaje p) {
    printf("%s tiene %d puntos de vida restantes.\n", p.nombre, p.vida);
}

int main() {
    srand(time(NULL));

    printf("¡Hola a todos! (¡Hola Isi!) ¡Bienvenidos al emocionante juego donde los héroes se enfrentan en una batalla épica!\n");
    printf("¡Prepárense para conocer a nuestros valientes luchadores!\n");
    printf("Presentando a los personajes:\n");

    Personaje evilBunny = {
        "EvilBunny",
        "¡Soy EvilBunny, el temido conejo oscuro de las sombras! ¡Nadie puede detenerme!",
        800,
        {"Booker T", "Tarot", "Tú no metes cabra"},
        {"Me fui de vacaciones", "Amorfoda", "Dakiti"},
        {500, 200, 350},
        {150, 100, 250},
        {0, 0, 0},
        {0, 0, 0}
    };

    Personaje almighty = {
        "Almighty",
        "¡Soy Almighty, el guerrero invencible del género! ¡Estoy aquí para demostrar mi poder!",
        1000,
        {"Esclava", "Asalto", "Soldado y Profeta"},
        {"Sólida", "Vacío", "Indiferente"},
        {400, 250, 300},
        {150, 100, 250},
        {0, 0, 0},
        {0, 0, 0}
    };

    printf("%s: %s\n", evilBunny.nombre, evilBunny.presentacion);
    printf("%s: %s\n", almighty.nombre, almighty.presentacion);

    while (!Derrotado(evilBunny) && !Derrotado(almighty)) {
        evilBunny = actualizarCooldowns(evilBunny);
        almighty = actualizarCooldowns(almighty);

        ResultadoAtaque resultado = atacar(&evilBunny, &almighty);
        almighty.vida -= resultado.daño_recibido;
        mostrarEstadisticas(almighty);
        if (Derrotado(almighty)) {
            printf("%s ha derrotado a %s. ¡Victoria para el lado oscuro!\n", evilBunny.nombre, almighty.nombre);
            break;
        }

        resultado = atacar(&almighty, &evilBunny);
        evilBunny.vida -= resultado.daño_recibido;
        mostrarEstadisticas(evilBunny);
        if (Derrotado(evilBunny)) {
            printf("%s ha derrotado a %s. ¡El guerrero invencible ha triunfado!\n", almighty.nombre, evilBunny.nombre);
            break;
        }
    }

    return 0;
}
