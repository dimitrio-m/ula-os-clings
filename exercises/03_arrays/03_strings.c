#include <stdio.h>

int main() {
    // En C, las cadenas deben terminar con un caracter nulo '\0'
    // para saber dónde acaban.
    
    char name[4] = {'U', 'L', 'A'}; // Falta el terminador
    
    // TODO: Esto podría imprimir basura después de "ULA" porque printf
    // sigue leyendo memoria hasta encontrar un 0.
    // Arregla la declaración del array para que sea seguro y válido.
    // Pista: El tamaño del array debe ser suficiente para las letras + el \0.

    printf("La universidad es: %s\n", name);
    return 0;
}
