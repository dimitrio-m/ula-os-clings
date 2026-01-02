#include <stdio.h>

int main() {
    int source[] = {10, 20, 30};
    int dest[3] = {0, 0, 0};

    // TODO: Copia los datos de source a dest MANUALMENTE usando un bucle.
    // No uses memcpy. Usa punteros o índices.
    
    // for (...) { dest[i] = ... }

    if (dest[0] == 10 && dest[2] == 30) {
        printf("✅ Copia manual exitosa.\n");
        return 0;
    }
    return 1;
}
