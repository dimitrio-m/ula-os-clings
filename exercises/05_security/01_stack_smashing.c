#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Simulamos una estructura de usuario en memoria
struct UserSession {
    char username[8];    // Solo caben 7 letras + \0
    int is_admin;        // 0 = No, 1 = Sí (Esto vive justo al lado en RAM)
};

int main() {
    struct UserSession session;
    session.is_admin = 0; // Por defecto NO es admin
    
    // Un hacker envía un nombre de usuario malicioso muy largo
    // "Hack1234" + caracteres extra para pisar la memoria vecina
    char *input_malicioso = "UsuarioNormalAAAAA"; 

    // ---------------------------------------------------------
    // CÓDIGO VULNERABLE (Tu misión es arreglar esto)
    // strcpy no verifica el tamaño del destino. Copia hasta encontrar un \0.
    // Esto desbordará 'username' y escribirá sobre 'is_admin'.
    
    strcpy(session.username, input_malicioso); // <--- CAMBIA ESTO
    
    // PISTA PARA ARREGLARLO:
    // Usa 'snprintf(destino, tamaño, "%s", fuente)' para limitar la copia.
    // Ejemplo: snprintf(session.username, 8, "%s", input_malicioso);
    // ---------------------------------------------------------

    printf("Usuario: %s\n", session.username);
    printf("Es Admin: %d\n", session.is_admin);

    // EL TEST:
    // Para pasar, debes evitar que 'is_admin' cambie de valor.
    // El usuario debe truncarse, pero la seguridad debe mantenerse.
    
    if (session.is_admin != 0) {
        printf("❌ ¡HACKEADO! El buffer overflow sobrescribió el permiso de admin.\n");
        return 1;
    }

    printf("✅ Seguro. El overflow fue contenido.\n");
    return 0;
}
