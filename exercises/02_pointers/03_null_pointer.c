#include <stdio.h>

int main() {
    int *ptr = NULL;
    int data = 100;

    // TODO: Este código va a explotar (Segmentation Fault) porque intentamos
    // leer de un puntero NULL.
    // Asigna la dirección de 'data' a 'ptr' antes de que el código llegue al printf.
    
    // --- ARREGLA AQUÍ ---
    
    // --------------------

    printf("El valor es: %d\n", *ptr);
    return 0;
}
