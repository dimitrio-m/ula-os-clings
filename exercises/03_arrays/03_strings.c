#include <stdio.h>

int main() {
    // INSTRUCCIÓN:
    // Define el arreglo de caracteres 'institution' para que contenga 
    // exactamente la palabra "ULA" y sea procesable de forma segura por 
    // las funciones estándar del sistema (como printf).
    // RESTRICCIÓN: Tienes estrictamente prohibido usar la notación de 
    // comillas dobles (ej: "ULA"). Debes inicializar los elementos usando llaves {}.

    char institution[] = {'U', 'L', 'A', '\0'}; // <--- MODIFICA ESTA LÍNEA

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (sizeof(institution) == 4) {
        if (institution[3] == '\0') {
            printf("✅ Correcto. Comprendes el byte centinela que delimita las cadenas de texto en C.\n");
            return 0;
        }
    }

    printf("❌ Peligro de lectura fuera de límites. A tu cadena le falta el terminador.\n");
    return 1;
}
