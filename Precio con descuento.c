#include <stdio.h>


struct producto {
    int id;
    float precio;
};


struct producto aplicarDescuento(struct producto p) {
    p.precio = p.precio * 0.8; 
    return p; 
}

int main() {
    struct producto prod;

    
    printf("Ingrese el ID del producto: ");
    scanf("%d", &prod.id);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &prod.precio);

    
    printf("Precio original: %.2f\n", prod.precio);

    
    prod = aplicarDescuento(prod);

    
    printf("Precio con descuento: %.2f\n", prod.precio);

    return 0;
}
