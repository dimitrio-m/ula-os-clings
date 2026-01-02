#include <unistd.h>
#include <sys/syscall.h> // Define SYS_write, SYS_exit, etc.

int main() {
    char *msg = "Hola desde el Kernel directo (sin wrapper)\n";
    
    // TAREA: En lugar de usar la función write(fd, buf, len),
    // usa la función syscall(NUMBER, arg1, arg2, arg3).
    
    // El número de la syscall de escritura es 'SYS_write' (o 1 en x86_64).
    // Los argumentos son: File Descriptor (1=stdout), Buffer, Longitud.
    
    // syscall(SYS_write, 1, msg, 42); <--- Implementa esto abajo
    
    long ret = 0; // CAMBIA ESTO

    if (ret > 0) {
        return 0; // Éxito
    }
    return 1;
}
