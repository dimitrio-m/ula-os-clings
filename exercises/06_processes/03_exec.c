#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/echo", "Hola desde Exec!", NULL};

    printf("Antes del exec...\n");

    // TODO: Usa execv (o execvp) para reemplazar este programa por 'echo'.
    // execv(ruta, argumentos);
    
    // execv(args[0], args); 

    // ---------------------------------------------------------
    // TRAMPA: Si execv tiene éxito, el sistema operativo
    // borra la memoria de este programa y carga el nuevo.
    // Por lo tanto, esta línea de abajo JAMÁS debería imprimirse.
    // ---------------------------------------------------------
    
    printf("❌ ERROR: Si ves esto, execv falló.\n");
    return 1;
}
