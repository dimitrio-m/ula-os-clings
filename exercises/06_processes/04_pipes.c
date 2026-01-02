#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; // fd[0] = Read, fd[1] = Write
    char buffer[20];

    // TODO: Inicializa la tubería. pipe(fd) devuelve 0 si tiene éxito.
    // if (pipe(fd) == -1) return 1;

    if (fork() == 0) {
        // HIJO: Lector
        close(fd[1]); // Cierra escritura (buena práctica)
        
        // TODO: Lee de la tubería (fd[0]) hacia 'buffer'.
        // read(fd[0], buffer, sizeof(buffer));

        if (strcmp(buffer, "Secreto") == 0) {
            printf("✅ Hijo: Recibí el mensaje secreto correctamente.\n");
            close(fd[0]); // Buena práctica: cerrar al terminar
            return 0; // Éxito
        } else {
            printf("❌ Hijo: Recibí basura o nada: '%s'\n", buffer);
            return 1;
        }
    } else {
        // PADRE: Escritor
        close(fd[0]); // Cierra lectura
        
        // Escribimos en la tubería
        char *mensaje = "Secreto";
        printf("Padre: Enviando mensaje...\n");
        write(fd[1], mensaje, strlen(mensaje));
        
        close(fd[1]); // Buena práctica: cerrar al terminar
        return 0; // El padre asume que el hijo hará su trabajo
    }
}
