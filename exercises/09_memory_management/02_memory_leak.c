#include <stdio.h>
#include <stdlib.h>

void process_data() {
    // Pedimos 1KB de memoria
    int *data = malloc(1024 * sizeof(int));
    
    if (data == NULL) return;

    data[0] = 42; // Usamos la memoria
    printf("Procesando datos: %d\n", data[0]);

    // TODO: ¡Falta algo aquí!
    // Si la función termina sin liberar 'data', ocurre un Memory Leak.
    // El AddressSanitizer (check.sh) te gritará si no arreglas esto.
    
    // free(data);
}

int main() {
    // Llamamos a la función varias veces
    for (int i = 0; i < 5; i++) {
        process_data();
    }
    
    // Si el script llega aquí sin errores de Sanitizer, pasaste.
    return 0;
}
