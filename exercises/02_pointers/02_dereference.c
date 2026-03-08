#include <stdio.h>

int main() {
    int secure_flag = 0x0;
    int *access_port = &secure_flag;

    // INSTRUCCIÓN:
    // Escribe el valor hexadecimal 0xDEADBEEF en la dirección de memoria 
    // a la que apunta 'access_port'.
    // RESTRICCIÓN: Tienes estrictamente prohibido utilizar, nombrar o reasignar la 
    // variable 'secure_flag' directamente.
    
    // <--- ESCRIBE TU CÓDIGO AQUÍ ABAJO --->
    *access_port = 0xDEADBEEF; 
    //La instrucción sería más clara de la siguiente forma: Escribe el valor hexadecimal 0xDEADBEEF en la variable a cuya dirección de memoria apunta 'access_port' 

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (secure_flag == 0xDEADBEEF) {
        printf("✅ Correcto. Operación de escritura indirecta (dereferencia) exitosa.\n");
        return 0;
    }

    printf("❌ Acceso denegado. El flag de seguridad no fue modificado en memoria.\n");
    return 1;
}
