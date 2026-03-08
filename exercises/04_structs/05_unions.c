#include <stdio.h>
#include <stdint.h>

union HardwareRegister {
    uint32_t full_value;
    uint8_t bytes[4];
};

int main() {
    union HardwareRegister reg;
    reg.full_value = 0xFF00AA11;

    // INSTRUCCIÓN:
    // Extrae el byte menos significativo de 'full_value' utilizando 
    // exclusivamente el arreglo 'bytes' de la unión. Asigna el resultado a 'low_byte'.
    
    uint8_t low_byte = reg.bytes[0]; // <--- MODIFICADA
    //Investigar sobre union y el Endianness de la arquitectura resultó ser clave para resolver esta instrucción correctamente.

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (low_byte == 0x11) {
        printf("✅ Correcto. Comprendes el solapamiento de memoria y el Endianness de tu arquitectura.\n");
        return 0;
    }
    
    printf("❌ Fallo en la lectura del registro.\n");
    return 1;
}
