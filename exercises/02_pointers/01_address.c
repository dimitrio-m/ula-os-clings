#include <stdio.h>

int main() {
    int valor_secreto = 1234;
    int *puntero = NULL;

    // TODO: Haz que 'puntero' guarde la DIRECCIÓN de memoria de 'valor_secreto'.
    // Pista: Usa el operador '&' (address-of).
    
    // ESCRIBE TU CÓDIGO AQUÍ ABAJO:
    

    if (puntero == &valor_secreto) {
        printf("¡Bien! El puntero apunta a la dirección %p\n", (void*)puntero);
        return 0;
    }
    return 1;
}
