#include <stdio.h>

// Definimos un Nodo para una lista enlazada de Procesos
struct Process {
    int pid;
    // TODO: Falta el puntero al siguiente proceso.
    // No puede ser 'struct Process next;', tiene que ser un PUNTERO.
    // Defínelo aquí abajo llamándolo 'next'.
    
    struct Process *next; // <--- (El estudiante debe escribir esto, o algo similar)
};

int main() {
    struct Process p1 = {101, NULL};
    struct Process p2 = {102, NULL};

    // TODO: Enlaza p1 con p2.
    // Haz que el campo 'next' de p1 apunte a la DIRECCIÓN de p2.
    
    // p1.next = ...

    if (p1.next == &p2 && p1.next->pid == 102) {
        printf("✅ ¡Conexión exitosa! p1 sabe quién es p2.\n");
        return 0;
    }

    return 1;
}
