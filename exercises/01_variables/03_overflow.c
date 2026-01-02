#include <stdio.h>
#include <stdint.h> // Para tipos exactos como uint8_t

int main() {
    // Un uint8_t es un byte sin signo. Rango: 0 a 255.
    uint8_t contador_pequeno = 255;

    // TODO: Al sumar 1 a 255, ocurre un "Overflow" y vuelve a 0.
    // Esto es peligroso en sistemas reales.
    // Cambia el tipo de dato de 'contador_pequeno' para que pueda almacenar 300.
    // Pista: uint16_t (2 bytes) o int.
    
    contador_pequeno = contador_pequeno + 5; 

    // Queremos que el resultado sea 260
    if (contador_pequeno == 4) {
        printf("⚠️ ¡Cuidado! Ocurrió un overflow. 255 + 5 dio 4.\n");
        return 1;
    } else if (contador_pequeno == 260) {
        printf("✅ ¡Correcto! Ampliaste la capacidad del contenedor.\n");
        return 0;
    }

    return 1;
}
