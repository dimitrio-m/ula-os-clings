#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "/tmp/mi_chat_secreto"

int main() {
    // 1. Crear la FIFO (es como crear un archivo, pero especial)
    // Permisos 0666: Lectura/Escritura para todos
    // mkfifo devuelve -1 si ya existe (lo cual está bien)
    mkfifo(FIFO_FILE, 0666);

    if (fork() == 0) {
        // --- HIJO: ESCRITOR ---
        // Abre la FIFO como si fuera un archivo de texto
        int fd = open(FIFO_FILE, O_WRONLY);
        
        // TODO: Escribe "Hola Mundo" en el fd
        // write(fd, "Hola Mundo", 10);
        
        close(fd);
        return 0;
    } else {
        // --- PADRE: LECTOR ---
        // El open se bloquea hasta que el escritor abra su lado
        int fd = open(FIFO_FILE, O_RDONLY);
        char buf[20];
        
        // TODO: Lee de la FIFO
        // read(fd, buf, sizeof(buf));
        
        close(fd);
        
        // Limpiamos el archivo especial
        unlink(FIFO_FILE);

        if (strncmp(buf, "Hola Mundo", 10) == 0) {
            printf("✅ Comunicación por FIFO exitosa.\n");
            return 0;
        }
        return 1;
    }
}
