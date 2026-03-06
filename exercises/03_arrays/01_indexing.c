#include <stdio.h>

int main() {
    int memory_buffer[5] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE};

    // INSTRUCCIÓN:
    // Extrae el valor del último bloque válido del arreglo 'memory_buffer'
    // utilizando el operador de indexación '[]' y asígnalo a 'tail_data'.
    // RESTRICCIÓN: Tienes estrictamente prohibido acceder a memoria fuera 
    // de los límites definidos del arreglo (Out-of-Bounds).

    int tail_data = memory_buffer[4]; // <--- MODIFICA ESTA LÍNEA

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (tail_data == 0xEE) {
        printf("✅ Correcto. Entiendes la indexación base y los límites de memoria contigua.\n");
        return 0;
    }

    printf("❌ Violación de límites o lectura de basura. Valor leído: 0x%X\n", tail_data);
    return 1;
}
