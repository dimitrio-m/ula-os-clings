#include <stdio.h>
#include <unistd.h>
#include <signal.h> // Para kill y constantes SIG...
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Hijo rebelde: Bucle infinito
        while(1) {
            printf("Hijo: No me quiero ir...\n");
            sleep(1);
        }
    } else {
        // PADRE
        sleep(1); // Le damos un segundo de vida
        printf("Padre: Se acabó.\n");

        // TODO: Usa kill(pid, SEÑAL) para terminar al hijo.
        // Usa SIGKILL (fuerza bruta) o SIGTERM (educado).
        
        // Verificamos si murió
        int status;
        waitpid(pid, &status, 0);

        if (WIFSIGNALED(status)) {
            printf("✅ El hijo fue terminado por una señal.\n");
            return 0;
        }
    }
    return 1;
}
