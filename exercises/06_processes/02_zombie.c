#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Hijo: Terminé mi trabajo.\n");
        return 42; // Código de salida del hijo
    } 
    else {
        // PADRE
        int status;
        
        // TODO: El hijo se quedará ZOMBIE si no lo esperamos.
        // Descomenta y usa waitpid para recoger su estado.
        
        // waitpid(pid, &status, 0);

        // Verificamos si recogimos el código 42
        if (WIFEXITED(status) && WEXITSTATUS(status) == 42) {
            printf("✅ Padre: El hijo terminó correctamente con 42.\n");
            return 0;
        }
    }
    return 1;
}
