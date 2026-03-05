#include <stdio.h>
#include <stdint.h>

int main() {
    // INSTRUCCIÓN:
    // Modifica exclusivamente el tipo de dato de la variable 'sensor_value' para prevenir
    // el desbordamiento aritmético (Integer Overflow) que ocurre en la suma.
    // RESTRICCIÓN: Tienes estrictamente prohibido alterar los valores numéricos 255 y 5.

    uint16_t sensor_value = 255; // <--- MODIFICA ESTA LÍNEA

    sensor_value = sensor_value + 5;

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (sensor_value == 260) {
        printf("✅ Correcto. Comprendes los límites de almacenamiento de las primitivas de hardware.\n");
        return 0;
    }

    printf("❌ Desbordamiento de enteros detectado. Fallo crítico de lectura. Valor actual: %d\n", sensor_value);
    return 1;
}
