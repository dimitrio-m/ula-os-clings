#include <stdio.h>
#include <sys/utsname.h> // Para uname

int main() {
    struct utsname info;

    // TAREA: Llama a uname pasando la dirección de 'info'.
    // uname(&info);
    
    if (uname(&info) != 0) {
        return 1; // Falló
    }

    printf("Sistema: %s\n", info.sysname); // Ej: Linux
    printf("Kernel: %s\n", info.release);  // Ej: 5.15.0-generic
    printf("Arquitectura: %s\n", info.machine); // Ej: x86_64

    // Validación simple: Si el nombre del sistema no está vacío, pasamos.
    if (info.sysname[0] != '\0') {
        return 0;
    }
    return 1;
}
