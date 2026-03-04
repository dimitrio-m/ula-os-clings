#include <stdio.h>

int main() {
    int buffer_a[] = {0x10, 0x20, 0x30, 0x40, 0x50};
    int buffer_b[5] = {0};

    // INSTRUCCIÓN:
    // Implementa la lógica necesaria para transferir la totalidad de los datos 
    // desde 'buffer_a' hacia 'buffer_b'.
    // RESTRICCIÓN 1: Tienes estrictamente prohibido el uso de funciones de la 
    // librería estándar como 'memcpy' o 'memmove'.
    // RESTRICCIÓN 2: Debes utilizar una estructura de control iterativa.

    // <--- ESCRIBE TU CÓDIGO AQUÍ ABAJO --->
    for(int i = 0; i < 5; i++) buffer_b[i] = buffer_a[i];
    
    // --- ZONA DE VALIDACIÓN (No modificar) ---
    int checksum = 0;
    for (int i = 0; i < 5; i++) checksum += buffer_b[i];

    if (checksum == 0xf0 && buffer_b[0] == 0x10 && buffer_b[4] == 0x50) {
        printf("✅ Correcto. Has replicado la estructura de memoria manualmente.\n");
        return 0;
    }

    printf("❌ Error de integridad. Los datos en el búfer de destino no coinciden con el origen.\n");
    return 1;
}
