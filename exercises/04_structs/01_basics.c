#include <stdio.h>
#include <string.h>

// Definimos un "struct" para un Estudiante
struct Student {
    char name[50];
    int age;
    float average;
};

int main() {
    // Inicialización
    struct Student s1;
    
    // TODO: Asigna los valores:
    // name -> "Juan"
    // age -> 20
    // average -> 19.5
    
    // Pista: Para strings usa strcpy(destino, fuente) o snprintf.
    // s1.age = ...
    
    // VALIDACIÓN:
    if (s1.age == 20 && s1.average > 19.0) {
        printf("✅ Estudiante creado correctamente.\n");
        return 0;
    }
    
    return 1;
}
