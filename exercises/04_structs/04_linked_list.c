#include <stdio.h>

struct Process {
    int pid;
    
    struct Process *next;
    // INSTRUCCIÓN 1:
    // Declara un miembro llamado 'next' capaz de almacenar la 
    // dirección de memoria de otra estructura 'Process'.
    
};

int main() {
    struct Process p1 = {101, NULL};
    struct Process p2 = {102, NULL};

    // INSTRUCCIÓN 2:
    // Modifica 'p1' para que su miembro 'next' apunte a 'p2'.
      
    p1.next = &p2;
    
    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (p1.next == &p2 && p1.next->pid == 102) {
        printf("✅ ¡Conexión exitosa! El bloque de control de procesos está enlazado.\n");
        return 0;
    }

    printf("❌ Error de segmentación o enlace incorrecto.\n");
    return 1;
}
