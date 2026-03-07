#include <stdio.h>

int process_request() {
    // INSTRUCCIÓN:
    // Modifica la declaración de la variable 'request_count' para que 
    // conserve su valor en memoria entre múltiples invocaciones a esta función.
    // RESTRICCIÓN: Tienes estrictamente prohibido mover la variable fuera de 
    // la función (no puede ser global).
    
    static int request_count = 0; // <--- MODIFICA ESTA LÍNEA
    
    request_count++;
    return request_count;
}

int main() {
    process_request();
    process_request();
    process_request();

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (process_request() == 4) {
        printf("✅ Correcto. Dominas la persistencia del estado local y su ciclo de vida.\n");
        return 0;
    }

    printf("❌ Fallo de estado. La variable pierde su memoria en cada invocación.\n");
    return 1;
}
