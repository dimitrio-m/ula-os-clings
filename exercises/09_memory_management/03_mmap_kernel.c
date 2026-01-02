#include <stdio.h>
#include <sys/mman.h> // Para mmap
#include <unistd.h>   // Para sysconf

int main() {
    // Obtenemos el tamaño de una página de memoria (usualmente 4096 bytes)
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Tamaño de página del sistema: %ld bytes\n", page_size);

    // TAREA: Usar mmap para pedir una página de memoria cruda al Kernel.
    // Prototipo: mmap(addr, length, prot, flags, fd, offset)
    
    // PROT_READ | PROT_WRITE -> Queremos leer y escribir
    // MAP_PRIVATE | MAP_ANONYMOUS -> Memoria privada, no vinculada a archivo
    
    char *memory = mmap(NULL, page_size, 
                        PROT_READ | PROT_WRITE, 
                        MAP_PRIVATE | MAP_ANONYMOUS, 
                        -1, 0);

    if (memory == MAP_FAILED) {
        printf("❌ Falló mmap\n");
        return 1;
    }

    // Escribimos en esa memoria "virgen"
    sprintf(memory, "Esta memoria viene directo del Kernel");

    printf("Mensaje: %s\n", memory);

    // Liberamos la memoria (munmap es el free del kernel)
    if (munmap(memory, page_size) == -1) {
        return 1;
    }

    printf("✅ Gestión de memoria de bajo nivel exitosa.\n");
    return 0;
}
