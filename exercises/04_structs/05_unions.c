#include <stdio.h>
#include <stdint.h>

// Una unión comparte el MISMO espacio de memoria para todos sus campos.
union HardwareRegister {
    uint32_t full_value; // 4 bytes (ej: 0xAABBCCDD)
    uint8_t bytes[4];    // Array de 4 bytes individuales
};

int main() {
    union HardwareRegister reg;
    
    // Asignamos un valor hexadecimal grande (4 bytes)
    reg.full_value = 0xFF00AA11;

    // TODO: Accede al byte menos significativo (el último a la derecha, 0x11).
    // En arquitectura Little Endian, suele ser el byte[0].
    // Usa la "vista" de array de la unión para sacar ese valor.
    
    uint8_t low_byte = 0; // <--- CAMBIA ESTO (ej: reg.bytes[0])

    printf("El byte bajo es: 0x%X\n", low_byte);

    if (low_byte == 0x11) {
        printf("✅ Entendiste cómo las Unions solapan memoria.\n");
        return 0;
    }
    
    printf("❌ Esperaba 0x11 (17 decimal).\n");
    return 1;
}
