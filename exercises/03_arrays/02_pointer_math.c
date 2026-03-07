#include <stdio.h>

int main() {
    int data_stream[] = {10, 20, 30, 40, 50};
    int *base_ptr = data_stream; 

    // INSTRUCCIÓN:
    // Utilizando exclusivamente aritmética de punteros sobre 'base_ptr',
    // calcula la dirección de memoria del elemento cuyo valor original es 30
    // y asígnala a 'target_ptr'.
    // RESTRICCIÓN: Tienes estrictamente prohibido usar el operador de indexación '[]'.
    
    int *target_ptr = base_ptr + 2; // <--- MODIFICA ESTA LÍNEA
    // con el for se puede hacer de manera mas general

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (target_ptr != NULL) {
        // Sobrescribimos la memoria en la dirección que calculaste
        *target_ptr = 999; 
    }

    // Verificamos si la sobrescritura ocurrió en la posición correcta del arreglo
    if (data_stream[2] == 999) {
        printf("✅ Correcto. Dominas el desplazamiento en bloques de memoria.\n");
        return 0;
    }

    printf("❌ Desplazamiento incorrecto. Modificaste la región de memoria equivocada.\n");
    return 1;
}
