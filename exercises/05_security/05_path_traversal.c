#include <stdio.h>
#include <string.h>

int main() {
    // Simulamos una petición GET
    char *filename = "../../etc/passwd";
    
    // Directorio raíz donde están los archivos públicos
    char *root_dir = "/var/www/html/";

    // ---------------------------------------------------------
    // TAREA DE SEGURIDAD
    // Debes detectar si el filename intenta subir de directorio ("..")
    // Usa strstr() para buscar la subcadena "..".
    
    int es_seguro = 1; // Asumimos seguro por defecto (MAL)

    // TODO: Implementa la lógica aquí. Si contiene "..", es_seguro = 0.
    
    if (strstr(filename, "..") != NULL) {
        // ARREGLA ESTO: Descomenta la línea de abajo o implementa tu lógica
        // es_seguro = 0;
    }
    // ---------------------------------------------------------

    if (es_seguro == 0) {
        printf("✅ Ataque bloqueado. Intento de Path Traversal detectado.\n");
        return 0;
    } else {
        printf("❌ FALLO: Permitiste acceso a %s\n", filename);
        return 1;
    }
}
