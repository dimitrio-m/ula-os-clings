#include <stdio.h>

int main() {
    int a = 10;
    float b = 5.5;
    
    // TODO: Queremos imprimir la suma, pero el especificador de formato está mal.
    // %d es para enteros decimales. ¿Cuál es para punto flotante?
    float suma = a + b;

    // CAMBIA LA SIGUIENTE LÍNEA:
    printf("La suma es: %d\n", suma);

    if (suma == 15.5) {
        return 0;
    }
    return 1;
}
