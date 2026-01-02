#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr; // Apunta al 10

    // TODO: Sin usar arr[2], usa aritmética de punteros para obtener el 30.
    // Recuerda: ptr + 1 avanza una posición (4 bytes), no 1 byte.
    
    int *ptr_al_30 = ptr; // <--- MODIFICA ESTA LÍNEA (ej: ptr + algo)

    if (*ptr_al_30 == 30) {
        printf("¡Correcto! Accediste a %d usando matemáticas.\n", *ptr_al_30);
        return 0;
    }
    printf("Incorrecto. Apuntas a %d\n", *ptr_al_30);
    return 1;
}
