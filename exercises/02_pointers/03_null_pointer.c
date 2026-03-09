#include <stdio.h>

int main() {
    int safe_data = 100;
    int *danger_ptr = NULL;

    // INSTRUCCIÓN:
    // Escribe el código necesario para redirigir el flujo y evitar un 
    // fallo de segmentación (Segmentation Fault) en la zona de validación.
    // RESTRICCIÓN: Tienes estrictamente prohibido modificar las líneas de 
    // declaración inicial de las variables.
    
    // <--- ESCRIBE TU CÓDIGO AQUÍ ABAJO --->
    danger_ptr = &safe_data; 

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (danger_ptr == NULL) {
        printf("❌ Segmentation Fault (Simulado). El puntero intentó acceder a la dirección 0x0.\n");
        return 1;
    }

    if (*danger_ptr == 100) {
        printf("✅ Correcto. Has redirigido el puntero a una región de memoria válida y segura.\n");
        return 0;
    }

    printf("❌ El puntero no es nulo, pero no apunta al dato esperado.\n");
    return 1;
}
