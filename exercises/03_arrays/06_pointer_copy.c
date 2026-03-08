#include <stdio.h>

int main() {
    int source_block[] = {100, 200, 300, 400};
    int dest_block[4] = {0};

    // INSTRUCCIÓN:
    // Transfiere todos los elementos de 'source_block' a 'dest_block' utilizando 
    // exclusivamente aritmética de punteros.
    // RESTRICCIÓN 1: Tienes estrictamente prohibido usar el operador de indexación '[]' 
    // dentro de tu bucle (ej: no puedes usar dest[i]).
    // RESTRICCIÓN 2: No puedes usar funciones de librería como 'memcpy'.

    int *src_ptr = source_block;
    int *dst_ptr = dest_block;

    // <--- ESCRIBE TU BUCLE AQUÍ ABAJO --->
    for (int i = 0; i < 4; i++) {
        *dst_ptr = *src_ptr;
        dst_ptr++;
        src_ptr++;
    }

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (dest_block[0] == 100 && dest_block[3] == 400) {
        printf("✅ Correcto. Has manipulado la memoria directamente mediante aritmética de punteros.\n");
        return 0;
    }

    printf("❌ Fallo en la transferencia. El destino no refleja los datos originales.\n");
    return 1;
}
