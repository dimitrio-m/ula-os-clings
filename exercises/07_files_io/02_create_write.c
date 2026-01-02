#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char *mensaje = "Sistema Iniciado\n";
    
    // TAREA: Completa las banderas de open.
    // 1. O_WRONLY: Queremos escribir.
    // 2. O_CREAT: Si no existe, créalo.
    // 3. O_TRUNC: Si existe, borra su contenido (piénsalo como sobrescribir).
    // IMPORTANTE: Como usamos O_CREAT, necesitamos el tercer argumento (permisos): 0644.
    
    // int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int fd = -1; // <--- ARREGLA ESTO

    if (fd == -1) {
        printf("❌ Falló el open.\n");
        return 1;
    }

    // Escribimos el mensaje
    ssize_t bytes = write(fd, mensaje, strlen(mensaje));

    close(fd);
    // Borramos el archivo para no ensuciar el repo
    unlink("log.txt"); 

    if (bytes == (ssize_t)strlen(mensaje)) {
        printf("✅ Archivo creado y escrito correctamente.\n");
        return 0;
    }
    return 1;
}
