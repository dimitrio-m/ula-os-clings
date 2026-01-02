#include <stdio.h>
#include <fcntl.h>
#include <errno.h>  // <--- Aquí vive la variable mágica
#include <string.h>

int main() {
    // Intentamos abrir un archivo que seguro no existe
    int fd = open("/archivo_fantasma.txt", O_RDONLY);

    if (fd == -1) {
        // TAREA: El Kernel nos dijo "Error".
        // Verifica si el código de error (errno) es ENOENT (No such file or directory).
        
        // if (errno == ENOENT) ...
        
        // Pista extra: printf puede imprimir el mensaje humano usando strerror(errno)
        printf("Error detectado: %s\n", strerror(errno));

        // CAMBIA LA CONDICIÓN:
        if (errno == 0) { // <--- ESTO ESTÁ MAL, errno no será 0 si falló
             return 1;
        } else {
             printf("✅ Detectamos correctamente el error ENOENT.\n");
             return 0;
        }
    }
    
    return 1; // Si por milagro el archivo existe, fallamos el test
}
