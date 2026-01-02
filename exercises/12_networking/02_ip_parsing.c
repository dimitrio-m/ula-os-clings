#include <stdio.h>
#include <arpa/inet.h>

int main() {
    char *ip_str = "192.168.1.1";
    struct sockaddr_in sa;

    // TAREA: Convierte el string IP a binario y guárdalo en sa.sin_addr.
    // inet_pton(AF_INET, ip_str, &(sa.sin_addr));
    
    int result = 0; // <--- ARREGLA ESTO (llama a inet_pton)

    // inet_pton devuelve 1 si tuvo éxito.
    if (result == 1) {
        printf("✅ IP convertida a binario correctamente.\n");
        return 0;
    }
    
    printf("❌ Falló la conversión de IP.\n");
    return 1;
}
