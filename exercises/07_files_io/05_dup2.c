#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int archivo = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    // Guardamos una copia del stdout original (opcional, por si queremos volver)
    // int original_stdout = dup(STDOUT_FILENO);

    // TAREA: Reemplaza STDOUT_FILENO (1) con 'archivo'.
    // dup2(old_fd, new_fd);
    
    // dup2(archivo, STDOUT_FILENO); 

    // ------------------------------------------------
    // Si hiciste el dup2 bien, este printf NO saldrá en pantalla,
    // se escribirá dentro de "salida.txt".
    printf("Esto es un secreto redirigido");
    fflush(stdout); // Importante: vaciar el buffer de C
    // ------------------------------------------------

    close(archivo);

    // VERIFICACIÓN (Leemos el archivo para ver si tiene el texto)
    char buffer[100] = {0};
    int fd_check = open("salida.txt", O_RDONLY);
    read(fd_check, buffer, 100);
    close(fd_check);
    unlink("salida.txt");

    if (strstr(buffer, "secreto redirigido")) {
        // Escribimos al stderr (2) porque el stdout (1) sigue redirigido o cerrado
        fprintf(stderr, "✅ Redirección exitosa.\n");
        return 0;
    }
    
    fprintf(stderr, "❌ El archivo estaba vacío. Falló dup2.\n");
    return 1;
}
