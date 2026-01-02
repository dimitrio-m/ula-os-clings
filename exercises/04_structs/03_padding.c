#include <stdio.h>

struct PackedData {
    char a; // 1 byte
    int b;  // 4 bytes
};

int main() {
    // Matemáticamente: 1 char (1) + 1 int (4) = 5 bytes.
    // Pero en arquitectura de 64 bits, el CPU prefiere leer bloques de 4 u 8 bytes.
    // Por eso añade "padding" (relleno) después del char.
    
    struct PackedData data;

    printf("Tamaño real en memoria: %lu bytes\n", sizeof(data));

    // TODO: Cambia la condición del IF.
    // NO ES 5. Adivina cuánto es (usualmente es el múltiplo de 4 más cercano).
    // O usa sizeof() en la condición para que sea siempre correcto.
    
    if (sizeof(data) == 5) { // <--- ESTO ESTÁ MAL, CAMBIALO
        printf("❌ Matemáticas puras, pero incorrecto en Sistemas.\n");
        return 1;
    } 
    
    printf("✅ Entendiste el Memory Padding. Tamaño real: %lu\n", sizeof(data));
    return 0;
}
