#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Boilerplate de servidor (ya visto en ejercicios anteriores)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = { .sin_family = AF_INET, .sin_addr.s_addr = INADDR_ANY, .sin_port = htons(9090) };
    bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 1);

    // Simulamos un cliente en un proceso hijo para probar la conexión
    if (fork() == 0) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(9090);
        inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
        
        // El hijo se conecta al padre
        connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        close(sock);
        return 0;
    }

    // --- PADRE (SERVIDOR) ---
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);
    
    // TAREA: Acepta la conexión entrante.
    // int new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
    
    int new_socket = -1; // <--- ARREGLA ESTO

    if (new_socket >= 0) {
        printf("✅ Conexión aceptada. File Descriptor: %d\n", new_socket);
        close(new_socket);
        close(server_fd);
        return 0;
    }
    
    return 1;
}
