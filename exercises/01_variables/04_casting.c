#include <stdio.h>

int main() {
    // Tenemos un número grande que cabe perfectamente en 4 bytes (int)
    int valor_grande = 1000;
    
    // TODO: Estamos forzando este número grande en una caja pequeña (char - 1 byte).
    // Un char (signed) usualmente va de -128 a 127.
    // El compilador cortará los bits que sobran.
    
    char valor_truncado = (char)valor_grande;

    printf("Valor original: %d\n", valor_grande);
    printf("Valor truncado (lo que guardó el char): %d\n", valor_truncado);

    // ARREGLA ESTO:
    // Cambia el tipo de 'valor_truncado' para que no pierda información.
    // Debe ser capaz de guardar el 1000.
    
    if (valor_truncado == 1000) {
        printf("✅ Los datos se preservaron correctamente.\n");
        return 0;
    }
    
    printf("❌ Perdiste datos en la conversión.\n");
    return 1;
}
