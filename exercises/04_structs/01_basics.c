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
    
    // TODO: Asigna los valores para pasar el test
    s1.age = 20;
    s1.average = 19.4;
    strcpy(s1.name, "Alice"); // Bucle for tambien funciona
    
    // VALIDACIÓN:
    if (s1.age == 20 && s1.average > 19.0 && strcmp(s1.name, "Alice") == 0) {
        printf("✅ Estudiante creado correctamente.\n");
        return 0;
    }
    
    return 1;
}
