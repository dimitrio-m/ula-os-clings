#include <stdio.h>

int main() {
    int val = 42;
    int *ptr1 = &val;
    int **ptr2 = &ptr1; // Puntero a puntero

    // TODO: Accede al valor 42 usando SOLO ptr2.
    // Necesitas de-referenciar dos veces.
    
    int result = 0; // <--- CAMBIA ESTO (ej: **ptr2)

    if (result == 42) {
        printf("✅ Entendiste la indirección múltiple.\n");
        return 0;
    }
    return 1;
}
