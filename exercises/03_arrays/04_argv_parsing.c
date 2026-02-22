#include <stdio.h>

int main() {
    char *cmd_args[] = {"/usr/bin/daemon", "--verbose", "--port=8080", NULL}; 

    // INSTRUCCIÓN:
    // Extrae el argumento que contiene la configuración del puerto desde el 
    // vector de argumentos 'cmd_args' y asígnalo al puntero 'target_arg'.
    // RESTRICCIÓN: Tienes estrictamente prohibido usar cadenas de texto literales 
    // en tu respuesta (ej: no puedes escribir "--port=8080").
    
    char *target_arg = NULL; // <--- MODIFICA ESTA LÍNEA

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (target_arg != NULL && target_arg[2] == 'p' && target_arg[7] == '8') {
        printf("✅ Correcto. Comprendes la estructura de punteros dobles del vector de argumentos.\n");
        return 0;
    }

    printf("❌ Argumento no encontrado o puntero inválido.\n");
    return 1;
}
