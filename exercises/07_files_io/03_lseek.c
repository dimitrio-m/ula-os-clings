#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Creamos un archivo temporal con contenido conocido
    int fd = open("seek_test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    write(fd, "ABCDEFGHIJ", 10); // 10 bytes

    // Ahora el "cursor" está al final (byte 10).
    // Queremos leer "HIJ" (los últimos 3).

    // TAREA: Mueve el cursor 3 bytes HIA ATRÁS desde el FINAL.
    // SEEK_SET (Inicio), SEEK_CUR (Actual), SEEK_END (Final).
    
    // lseek(fd, -3, SEEK_END);
    
    off_t pos = 0; // <--- CAMBIA ESTO (usa lseek)

    char buffer[4] = {0};
    read(fd, buffer, 3);
    
    close(fd);
    unlink("seek_test.txt");

    if (strcmp(buffer, "HIJ") == 0) {
        printf("✅ Saltaste al lugar correcto.\n");
        return 0;
    }
    printf("❌ Leíste '%s' en lugar de 'HIJ'.\n", buffer);
    return 1;
}
