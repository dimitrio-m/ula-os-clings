#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // TODO: fork() devuelve:
    // - 0 al proceso HIJO
    // - PID del hijo al proceso PADRE
    // - Negativo si falla
    
    pid_t pid = fork();

    if (pid == 0) {
        // Lógica del HIJO
        printf("Soy el hijo. Mi PID es %d\n", getpid());
        // TODO: Haz que el hijo retorne 0 (éxito)
        return 1; // <--- CAMBIA ESTO
    } 
    else if (pid > 0) {
        // Lógica del PADRE
        printf("Soy el padre. Creé al hijo %d\n", pid);
        return 0; // El padre termina con éxito
    }
    
    return 1; // Fallo el fork
}
