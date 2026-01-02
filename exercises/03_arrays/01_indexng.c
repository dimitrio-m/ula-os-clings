#include <stdio.h>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};

    // TODO: Estamos intentando acceder a una posición inválida.
    // Los arrays en C van de 0 a N-1.
    // AddressSanitizer debería gritarte si corres esto sin arreglarlo.
    
    int val = numbers[10]; // <--- ESTO ESTÁ MAL

    printf("El valor es %d\n", val);
    
    // Para pasar, simplemente accede al último elemento válido (el 5)
    if (val == 5) return 0;
    return 1;
}
