#include <stdio.h>

int main() {
    // INSTRUCCIÓN:
    // El siguiente arreglo de configuración tiene un error de sintaxis crítico 
    // que provocará un "Syntax Error" en tiempo de compilación.
    // Corrige la línea para que el compilador la acepte como una inicialización válida.
    // RESTRICCIÓN: Tienes estrictamente prohibido cambiar el nombre de la variable, 
    // su tipo de dato, o los valores numéricos internos.

    int sys_config[4] = {10, 20, 30, 40}; // <--- MODIFICA ESTA LÍNEA

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    // Nota: Si el código no compila, reprobaste el ejercicio automáticamente.
    
    if (sys_config[0] == 10 && sys_config[3] == 40) {
        printf("✅ Correcto. Dominas la semántica de inicialización vs dimensión de arreglos en C.\n");
        return 0;
    }

    printf("❌ Los valores de configuración están corruptos o mal asignados. Esto no es Javascript :D\n");
    return 1;
}
