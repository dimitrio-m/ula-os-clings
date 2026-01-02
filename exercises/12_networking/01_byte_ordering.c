#include <stdio.h>
#include <arpa/inet.h> // Para htons

int main() {
    unsigned short port = 8080; // 0x1F90 en Hex
    
    // TAREA: Convierte el puerto al formato de red (Big Endian).
    // unsigned short network_port = htons(port);
    
    unsigned short network_port = port; // <--- ARREGLA ESTO (usa htons)

    // En Little Endian (tu PC), 8080 es [90 1F]
    // En Network (Big Endian), debe ser [1F 90]
    
    // Verificamos si los bytes cambiaron de lugar (asumiendo x86)
    if (network_port != port) {
        printf("✅ Puerto convertido correctamente a Big Endian.\n");
        return 0;
    }
    
    printf("❌ Estás enviando el puerto en formato local. Nadie te escuchará.\n");
    return 1;
}
