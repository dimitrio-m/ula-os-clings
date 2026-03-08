#include <stdio.h>

struct RawData {
    char a;
    int b;
};

int main() {
    struct RawData data;
    
    // INSTRUCCIÓN:
    // El código actual asume un tamaño de 5 bytes, lo cual provocará que el programa falle.
    // Corrige el valor de la variable 'expected_size' para que el programa termine con éxito.
    // 
    // RESTRICCIÓN: Tienes estrictamente prohibido usar el operador sizeof() 
    // para asignar este valor. Debes analizar la estructura y escribir el literal entero exacto.

    int expected_size = 8; // <--- MODIFICADO
    // 1 byte del char + 3 bytes de padding + 4 bytes del int = 8 bytes en total

    if (sizeof(data) != expected_size) { 
        printf("❌ Error. Asumiste %d bytes, pero la memoria real ocupada es distinta.\n", expected_size);
        return 1;
    } 
    
    printf("✅ Superado. Entiendes la estructura real de los datos en memoria.\n");
    return 0;
}
