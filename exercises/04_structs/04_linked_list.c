#include <stdio.h>

struct Process {
    int pid;
    
    struct Process *next;
    
};

int main() {
    struct Process p1 = {101, NULL};
    struct Process p2 = {102, NULL};

    p1.next = &p2;
    
    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (p1.next == &p2 && p1.next->pid == 102) {
        printf("✅ ¡Conexión exitosa! El bloque de control de procesos está enlazado.\n");
        return 0;
    }

    printf("❌ Error de segmentación o enlace incorrecto.\n");
    return 1;
}
