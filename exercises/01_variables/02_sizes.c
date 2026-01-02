#include <stdio.h>

int main() {
    int entero = 42;
    double decimal = 3.14159;

    // En arquitectura de 64 bits (x86_64), un int suele ser 4 bytes
    // y un double suele ser 8 bytes.
    
    printf("Tamaño de int: %lu bytes\n", sizeof(entero));
    printf("Tamaño de double: %lu bytes\n", sizeof(decimal));

    // TODO: Haz que esta condición sea verdadera verificando los tamaños
    if (sizeof(decimal) < sizeof(entero)) { 
        printf("¡Algo anda mal con tu lógica de tamaños!\n");
        return 1;
    }

    printf("¡Correcto! El double ocupa más memoria (o igual) que el int.\n");
    return 0;
}
