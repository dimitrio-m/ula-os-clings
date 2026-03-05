#include <stdio.h>
#include <string.h> // Necesario para memcpy

int main() {
    double sensor_data[] = {1.5, 2.8, 3.4, 4.2, 5.9};
    double backup_storage[5] = {0};

    // INSTRUCCIÓN:
    // Utiliza la función 'memcpy' para copiar todos los elementos de 
    // 'sensor_data' hacia 'backup_storage' en una sola operación.
    // RESTRICCIÓN: Tienes estrictamente prohibido usar bucles (for/while). 
    // Debes calcular el tamaño total en bytes de forma dinámica usando 'sizeof'.
    
    // <--- ESCRIBE TU LLAMADA A memcpy AQUÍ ABAJO --->
    
    memcpy(backup_storage, sensor_data, sizeof(sensor_data));

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (backup_storage[0] == 1.5 && backup_storage[4] == 5.9) {
        printf("✅ Correcto. Has realizado una copia de bloques de memoria eficiente.\n");
        return 0;
    }

    printf("❌ Error de copia. El almacenamiento de respaldo está vacío o incompleto.\n");
    return 1;
}
