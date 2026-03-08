#include <stdio.h>
#include <stdint.h>

int main() {
    int original_signal = 1000;

    // INSTRUCCIÓN:
    // Modifica la declaración y el cast de la variable 'processed_signal' 
    // para evitar la pérdida de datos por truncamiento de bits (Data Truncation).
    // RESTRICCIÓN: Tienes estrictamente prohibido modificar el valor o tipo de 'original_signal'.
    // BONUS: puedes optimizar el tipo de 'processed_signal' para que ocupe menos memoria sin perder la integridad de los datos?

    uint16_t processed_signal = (uint16_t)original_signal; // <--- MODIFICA ESTA LÍNEA

    printf("%d\n", processed_signal);
    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (processed_signal == 1000) {
        printf("✅ Correcto. Has conservado la integridad de la estructura de bits original.\n");
        return 0;
    }

    printf("❌ Fallo de integridad de datos. Señal truncada a: %d\n", processed_signal);
    return 1;
}
