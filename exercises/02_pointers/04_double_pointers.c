#include <stdio.h>

int main() {
    int core_data = 0xAA;
    int *l1_ptr = &core_data;
    int **l2_ptr = &l1_ptr;

    // INSTRUCCIÓN:
    // Sobrescribe el valor almacenado en la memoria base (core_data) 
    // asignándole el valor hexadecimal 0xFF.
    // RESTRICCIÓN: Tienes estrictamente prohibido utilizar, leer o referenciar 
    // las variables 'core_data' o 'l1_ptr' en tu solución. 
    // Debes operar exclusivamente a través de 'l2_ptr'.
    
    // <--- ESCRIBE TU CÓDIGO AQUÍ ABAJO --->
    

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (core_data == 0xFF) {
        printf("✅ Correcto. Dominas la indirección múltiple y la navegación de punteros encadenados.\n");
        return 0;
    }

    printf("❌ Fallo de indirección. El valor en la memoria base original no fue alterado.\n");
    return 1;
}
