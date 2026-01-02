#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_greeting(char *name) {
    // -----------------------------------------------------
    // ERROR: 'buffer' es un array local en el STACK.
    // Cuando esta función termine, 'buffer' deja de existir.
    // Retornar &buffer es retornar una dirección fantasma.
    
    char buffer[100]; // <--- ESTO ES MEMORIA AUTOMÁTICA (STACK)
    
    // TAREA: Cambia la línea de arriba para usar malloc (HEAP).
    // char *buffer = malloc(100);
    // -----------------------------------------------------

    snprintf(buffer, 100, "Hola %s", name);
    return buffer; // Si es Stack, esto es ilegal. Si es Heap, es válido.
}

int main() {
    char *msg = create_greeting("Estudiante");
    
    // Si usaste Stack, aquí imprimirás basura o tendrás Segfault.
    printf("%s\n", msg);

    // Si usaste malloc, recuerda liberar la memoria
    // free(msg);

    // Validación simple
    if (msg != NULL && strncmp(msg, "Hola", 4) == 0) return 0;
    return 1;
}
