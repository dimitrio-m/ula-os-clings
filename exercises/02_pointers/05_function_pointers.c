#include <stdio.h>

int execution_flag = 0x0000;

void secure_routine() {
    execution_flag = 0x1A2B;
}

void delegate_execution(void (*callback)()) {
    // INSTRUCCIÓN 1:
    // Ejecuta la rutina que ha sido delegada a través del parámetro 'callback'.
    // RESTRICCIÓN: Tienes estrictamente prohibido llamar a 'secure_routine' 
    // de forma explícita o directa dentro de esta función.
    
    // <--- ESCRIBE TU CÓDIGO AQUÍ ABAJO --->
    callback();
}

int main() {
    // INSTRUCCIÓN 2:
    // Invoca la función 'delegate_execution' para que administre la 
    // ejecución de 'secure_routine'.
    
    // <--- ESCRIBE TU CÓDIGO AQUÍ ABAJO --->
    delegate_execution(secure_routine);

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (execution_flag == 0x1A2B) {
        printf("✅ Correcto. Dominas el salto de ejecución dinámico mediante callbacks.\n");
        return 0;
    }

    printf("❌ Fallo de delegación. El flujo de ejecución nunca alcanzó la rutina objetivo.\n");
    return 1;
}
