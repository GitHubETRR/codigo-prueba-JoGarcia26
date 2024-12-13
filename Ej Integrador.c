#include <stdio.h> 
#include <string.h>

#define MAX_LIBROS 5
#define MAX_VENTAS 10

typedef struct { 
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char titulo[50];
    char autor[30];
    float precio;
} Libro;

typedef struct {
    Libro libro;
    int cantidad;
    Fecha fecha;
} Venta;

int cargarLibros(Libro libros[], int totalLibros);
int realizarVenta(Libro libros[], int totalLibros, Venta ventas[], int totalVentas);
float calcularTotalVentas(Venta ventas[], int totalVentas);
void ventasPorLibro(Venta ventas[], int totalVentas);

int main() {
    Libro libros[MAX_LIBROS];
    Venta ventas[MAX_VENTAS];
    int totalLibros = 0, totalVentas = 0;
    int opcion;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Cargar libros\n");
        printf("2. Registrar una venta\n");
        printf("3. Calcular total de ventas\n");
        printf("4. Mostrar ventas por libro\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                totalLibros = cargarLibros(libros, totalLibros);
                break;
            case 2:
                totalVentas = realizarVenta(libros, totalLibros, ventas, totalVentas);
                break;
            case 3: {
                float total = calcularTotalVentas(ventas, totalVentas);
                printf("El total de las ventas es: %.2f\n", total);
                break;
            }
            case 4:
                ventasPorLibro(ventas, totalVentas);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

int cargarLibros(Libro libros[], int totalLibros) {
    if (totalLibros >= MAX_LIBROS) {
        printf("No se pueden cargar más libros.\n");
        return totalLibros;
    }

    int cantidad = MAX_LIBROS - totalLibros;
    printf("Puede cargar hasta %d libros.\n", cantidad);

    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el título del libro: ");
        scanf(" %[^\n]s", libros[totalLibros].titulo);
        printf("Ingrese el autor del libro: ");
        scanf(" %[^\n]s", libros[totalLibros].autor);
        printf("Ingrese el precio del libro: ");
        scanf("%f", &libros[totalLibros].precio);
        totalLibros++;
    }

    return totalLibros;
}

int realizarVenta(Libro libros[], int totalLibros, Venta ventas[], int totalVentas) {
    if (totalVentas >= MAX_VENTAS) {
        printf("No se pueden registrar más ventas.\n");
        return totalVentas;
    }

    char titulo[50];
    printf("Ingrese el título del libro vendido: ");
    scanf(" %[^\n]s", titulo);

    int indice = -1;
    for (int i = 0; i < totalLibros; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Libro no encontrado.\n");
        return totalVentas;
    }

    ventas[totalVentas].libro = libros[indice];
    printf("Ingrese la cantidad vendida: ");
    scanf("%d", &ventas[totalVentas].cantidad);
    printf("Ingrese la fecha (dd mm aaaa): ");
    scanf("%d %d %d", &ventas[totalVentas].fecha.dia, 
                      &ventas[totalVentas].fecha.mes, 
                      &ventas[totalVentas].fecha.anio);

    totalVentas++;
    printf("Venta registrada con éxito.\n");

    return totalVentas;
}

float calcularTotalVentas(Venta ventas[], int totalVentas) {
    float total = 0.0;

    for (int i = 0; i < totalVentas; i++) {
        total += ventas[i].libro.precio * ventas[i].cantidad;
    }

    return total;
}

void ventasPorLibro(Venta ventas[], int totalVentas) {
    char titulo[50];
    printf("Ingrese el título del libro: ");
    scanf(" %[^\n]s", titulo);

    int cantidadTotal = 0;
    for (int i = 0; i < totalVentas; i++) {
        if (strcmp(ventas[i].libro.titulo, titulo) == 0) {
            cantidadTotal += ventas[i].cantidad;
        }
    }

    if (cantidadTotal > 0) {
        printf("Total de ventas para '%s': %d unidades.\n", titulo, cantidadTotal);
    } else {
        printf("No se encontraron ventas para '%s'.\n", titulo);
    }
}
v
