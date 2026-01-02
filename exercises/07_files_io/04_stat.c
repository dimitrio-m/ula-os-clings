#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat file_info;

    // TAREA: Usa stat() para inspeccionar "exercises/07_files_io/04_stat.c"
    // (O la ruta relativa correcta según donde ejecutes).
    // stat("ruta", &struct);
    
    // int resultado = stat("exercises/07_files_io/04_stat.c", &file_info);
    int resultado = -1; // <--- ARREGLA ESTO

    // Truco: Si ejecutas el script desde la raiz, la ruta es esa.
    // Si falla, intenta con "./04_stat.c" si compilas manual.
    
    if (resultado == -1) {
        printf("❌ No encontré el archivo para analizar.\n");
        return 1;
    }

    printf("Tamaño del archivo: %ld bytes\n", file_info.st_size);
    printf("Número de Inodo: %ld\n", file_info.st_ino);

    // Validación: El archivo debe tener contenido (> 0 bytes)
    if (file_info.st_size > 0) {
        printf("✅ Información de metadatos obtenida.\n");
        return 0;
    }
    return 1;
}
