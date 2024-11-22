#include <stdio.h>
#include <string.h>

#define NUM_VENDEDORES 5
#define NUM_CALZADOS 10
#define MAXCHAR 20
#define DNI 10
#define DESC 30

typedef struct {
    char dni[DNI];
    char nombre[MAXCHAR];
    char apellido[MAXCHAR];
    char genero;
    int paresVendidos;
} Vendedor;

typedef struct {
    int idCalzado;
    char descripcion[DESC];
    int stock;
} Calzado;

void cargarVendedores(Vendedor vendedores[NUM_VENDEDORES]);
void cargarCalzados(Calzado calzados[NUM_CALZADOS]);
void registrarVenta(Vendedor vendedores[NUM_VENDEDORES], Calzado calzados[NUM_CALZADOS]);

int main() {
    Vendedor vendedores[NUM_VENDEDORES];
    Calzado calzados[NUM_CALZADOS];

    cargarVendedores(vendedores);
    cargarCalzados(calzados);

    char continuar = 'S';
    while (continuar == 'S' || continuar == 's') {
        registrarVenta(vendedores, calzados);
        printf("¿Desea registrar otra venta? (S/N): ");
        scanf(" %c", &continuar);
    }

    printf("Datos finales de los vendedores:\n");
    for (int i = 0; i < NUM_VENDEDORES; i++) {
        printf("Vendedor %s %s, pares vendidos: %d\n", vendedores[i].nombre, vendedores[i].apellido, vendedores[i].paresVendidos);
    }

    return 0;
}

void cargarVendedores(Vendedor vendedores[NUM_VENDEDORES]) {
    for (int i = 0; i < NUM_VENDEDORES; i++) {
        printf("Ingrese DNI del vendedor %d: ", i + 1);
        scanf("%s", vendedores[i].dni);
        printf("Ingrese nombre del vendedor %d: ", i + 1);
        scanf("%s", vendedores[i].nombre);
        printf("Ingrese apellido del vendedor %d: ", i + 1);
        scanf("%s", vendedores[i].apellido);
        printf("Ingrese género del vendedor %d (M/F): ", i + 1);
        scanf(" %c", &vendedores[i].genero);
        vendedores[i].paresVendidos = 0;  
    }
}

void cargarCalzados(Calzado calzados[NUM_CALZADOS]) {
    for (int i = 0; i < NUM_CALZADOS; i++) {
        printf("Ingrese ID del calzado %d: ", i + 1);
        scanf("%d", &calzados[i].idCalzado);
        printf("Ingrese descripción del calzado %d: ", i + 1);
        scanf("%s", calzados[i].descripcion);
        printf("Ingrese stock del calzado %d: ", i + 1);
        scanf("%d", &calzados[i].stock);
    }
}

void registrarVenta(Vendedor vendedores[NUM_VENDEDORES], Calzado calzados[NUM_CALZADOS]) {
    char dni[DNI];
    int idCalzado, i, j;

    printf("Ingrese DNI del vendedor: ");
    scanf("%s", dni);

    for (i = 0; i < NUM_VENDEDORES; i++) {
        if (strcmp(vendedores[i].dni, dni) == 0) {
            break;
        }
    }

    if (i == NUM_VENDEDORES) {
        printf("Vendedor no encontrado.\n");
        return;
    }

    printf("Ingrese ID del calzado vendido: ");
    scanf("%d", &idCalzado);

    for (j = 0; j < NUM_CALZADOS; j++) {
        if (calzados[j].idCalzado == idCalzado) {
            break;
        }
    }

    if (j == NUM_CALZADOS) {
        printf("Calzado no encontrado.\n");
        return;
    }

    if (calzados[j].stock > 0) {
        calzados[j].stock--;  
        vendedores[i].paresVendidos++;
        printf("Venta registrada exitosamente.\n");
    } else {
        printf("No hay stock disponible para este calzado.\n");
    }
}
