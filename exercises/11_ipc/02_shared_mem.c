#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Pedimos memoria que pueda ser compartida entre procesos (MAP_SHARED)
    // int *counter = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    
    // TAREA: La línea de arriba está comentada. Descoméntala para que funcione.
    // Si usas malloc, esto fallará porque el heap es privado para cada proceso.
    int *counter = NULL; // <--- ARREGLA ESTO

    if (counter == NULL) return 1;

    *counter = 0; // Valor inicial

    if (fork() == 0) {
        // HIJO
        printf("Hijo: Incrementando contador...\n");
        (*counter)++; // Cambia el valor en memoria compartida
        return 0;
    } else {
        // PADRE
        wait(NULL); // Espera al hijo
        
        printf("Padre: El contador vale %d\n", *counter);
        
        // Si fuera memoria normal (privada), valdría 0.
        // Si es compartida, vale 1.
        if (*counter == 1) {
            printf("✅ Memoria compartida correctamente.\n");
            return 0;
        }
        return 1;
    }
}
