#include <stdio.h>
#include <assert.h>

int main() {
    int target = 10;
    int *ptr = &target;

    // TODO: Usa el puntero 'ptr' para cambiar el valor de 'target' a 50.
    // No puedes escribir 'target = 50;'. Debes usar el operador '*' (dereferencia).
    
    // ESCRIBE TU CÓDIGO AQUÍ:


    if (target == 50) {
        printf("¡Excelente! Cambiaste el valor remotamente.\n");
        return 0;
    }
    printf("Fallaste. Target sigue valiendo %d\n", target);
    return 1;
}
