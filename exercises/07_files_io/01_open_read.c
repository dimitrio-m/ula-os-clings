#include <stdio.h>
#include <fcntl.h>  // open
#include <unistd.h> // read, close

int main() {
    // Vamos a leer este mismo archivo fuente
    // O_RDONLY: Solo lectura
    int fd = open("exercises/07_files_io/01_open_read.c", O_RDONLY);

    if (fd == -1) {
        printf("❌ No pude abrir el archivo. ¿Estás ejecutando desde la raíz del repo?\n");
        return 1;
    }

    char buffer[10];
    
    // TODO: Lee 5 bytes del archivo y guárdalos en 'buffer'.
    // read(file_descriptor, buffer_destino, cantidad);
    
    ssize_t bytes_leidos = 0; // <--- CAMBIA ESTO (usa read)

    // Cerramos el archivo (buena práctica)
    close(fd);

    // El archivo empieza con "#incl", así que verificamos eso
    if (bytes_leidos == 5 && buffer[0] == '#') {
        printf("✅ Leíste el archivo a bajo nivel.\n");
        return 0;
    }
    
    return 1;
}
