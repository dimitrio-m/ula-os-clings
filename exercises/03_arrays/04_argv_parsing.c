#include <stdio.h>

int main() {
    // Simulamos lo que recibe el main: un array de cadenas
    char *args[] = {"ls", "-l", "-a", NULL}; 

    // TODO: Queremos acceder al tercer argumento ("-a").
    // Recuerda: args[0] es "ls".
    
    char *target = "nada"; // <--- CAMBIA ESTO (usa args)

    // Validación simple del primer caracter
    if (target[1] == 'a') { 
        printf("✅ Encontraste el argumento '-a'.\n");
        return 0;
    }
    return 1;
}
