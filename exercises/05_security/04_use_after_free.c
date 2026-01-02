#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[10];
    int id;
};

int main() {
    struct User *u = malloc(sizeof(struct User));
    strcpy(u->name, "Admin");
    u->id = 1;

    printf("Usuario creado: %s\n", u->name);

    // Liberamos la memoria porque el usuario "se desconectó"
    free(u);

    // ---------------------------------------------------------
    // CÓDIGO VULNERABLE
    // 'u' es ahora un "Dangling Pointer" (Puntero colgante).
    // Todavía apunta a la dirección de memoria, pero ya no nos pertenece.
    // Acceder a u->name aquí es indefinido (y peligroso).
    
    // TAREA: Después de un free, SIEMPRE asigna NULL al puntero para evitar accidentes.
    // u = NULL;
    // ---------------------------------------------------------

    // Simulamos que el sistema reutiliza esa memoria para otra cosa
    // (En un ataque real, el hacker controla esto)
    int *hack = malloc(sizeof(struct User));
    *hack = 99999; 

    // Intentamos usar el puntero viejo. 
    // Si u fuera NULL, esto causaría un crash controlado (mejor que un hack silencioso).
    if (u != NULL) {
        printf("❌ PELIGRO: 'u' sigue apuntando a memoria (%p).\n", (void*)u);
        return 1;
    }

    printf("✅ Seguro. El puntero fue anulado después del free.\n");
    return 0;
}
