#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_fd;
    struct sockaddr_in address;

    // 1. Crear Socket (TCP)
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) return 1;

    // 2. Configurar el struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Escuchar en todas las interfaces
    
    // TAREA: Falta configurar el puerto 8080 usando htons.
    // address.sin_port = htons(8080);
    
    address.sin_port = 0; // <--- ARREGLA ESTO

    // 3. Bind (Intentar reservar el puerto)
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("❌ Falló el bind. (¿Quizás no usaste htons?)\n");
        return 1;
    }

    printf("✅ Socket amarrado al puerto 8080.\n");
    close(server_fd);
    return 0;
}
