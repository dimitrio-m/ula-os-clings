#include <stdio.h>

int main() {
    int target_register = 0xABCD;
    int *memory_ptr = NULL;

    // INSTRUCCIÓN:
    // Asigna la dirección de memoria de la variable 'target_register' 
    // al puntero 'memory_ptr'.
    
    memory_ptr = &target_register;
    

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (memory_ptr != NULL) {
        // Intentamos reescribir la memoria usando tu puntero
        *memory_ptr = 0xFFFF; 
    }

    // Verificamos si la variable original fue la que realmente cambió
    if (target_register == 0xFFFF) {
        printf("✅ Correcto. Has establecido correctamente el enlace referencial.\n");
        return 0;
    }
    
    printf("❌ Referencia nula o incorrecta. Tu puntero no apunta al registro objetivo.\n");
    return 1;
}
