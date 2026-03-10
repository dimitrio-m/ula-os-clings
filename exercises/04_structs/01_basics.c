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
    s1.average = 20.0;
    s1.name[0] = 'A';
    s1.name[1] = 'l';
    s1.name[2] = 'i';
    s1.name[3] = 'c';
    s1.name[4] = 'e';
    s1.name[5] = '\00';

    
    // VALIDACIÓN:
    if (s1.age == 20 && s1.average > 19.0 && strcmp(s1.name, "Alice") == 0) {
        printf("✅ Estudiante creado correctamente.\n");
        return 0;
    }
    
    return 1;
}
