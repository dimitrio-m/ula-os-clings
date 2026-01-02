#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Variable global para comunicarnos con el handler
int signal_caught = 0;

// Esta función se ejecuta cuando llega la señal
void handle_sigint(int sig) {
    printf("\n¡Jaja! ¡No puedes matarme con Ctrl+C (o kill)!\n");
    signal_caught = 1;
}

int main() {
    // TAREA: Registra el manejador de señales.
    // signal(SIGINT, handle_sigint);
    
    // signal(SIGINT, ...); <--- IMPLEMENTA ESTO

    printf("Enviando señal SIGINT a mí mismo...\n");
    
    // Nos auto-enviamos la señal que usualmente mata al programa
    kill(getpid(), SIGINT);

    if (signal_caught == 1) {
        printf("✅ Sobreviviste y atrapaste la señal.\n");
        return 0;
    }
    
    printf("❌ El programa murió o no atrapó la señal.\n");
    return 1;
}
