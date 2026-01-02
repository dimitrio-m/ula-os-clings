#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Creamos 3 hijos
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            printf("Hijo %d naciendo...\n", i);
            return 0; // El hijo muere al instante
        }
    }

    int hijos_recogidos = 0;

    // TODO: Ahora debemos esperar a los 3.
    // wait(NULL) devuelve el PID del hijo que terminó o -1 si no hay más hijos.
    // Haz un bucle while que llame a wait(NULL) hasta que devuelva -1.
    
    if (hijos_recogidos == 3) {
        printf("✅ Padre: Todos mis hijos han terminado en paz.\n");
        return 0;
    }
    
    printf("❌ Aún quedan zombies sueltos o no esperaste a todos.\n");
    return 1;
}
