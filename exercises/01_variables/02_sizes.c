#include <stdio.h>
#include <stddef.h>

int main() {
    long memory_blocks[128];

    // INSTRUCCIÓN:
    // Calcula dinámicamente la cantidad de elementos del arreglo 'memory_blocks' 
    // utilizando el operador 'sizeof'. 
    // RESTRICCIÓN: Tienes estrictamente prohibido escribir el número 128.
    
    size_t array_length = 0; // <--- MODIFICA ESTA LÍNEA

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (array_length == 128) {
        printf("✅ Correcto. Dominas el cálculo de longitudes de arreglos en tiempo de compilación.\n");
        return 0;
    }

    printf("❌ Tamaño calculado incorrectamente. Revisa tu aritmética de punteros/tamaños.\n");
    return 1;
}
