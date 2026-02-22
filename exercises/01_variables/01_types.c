#include <stdio.h>

int main() {
    int a = 10;
    float b = 5.5;
    
    float suma = a + b;

    // INSTRUCCIÓN:
    // La siguiente llamada a 'printf' provocará un comportamiento indefinido 
    // y mostrará basura en pantalla debido a un desajuste de tipos (Type Mismatch). 
    // Corrige el especificador de formato para que imprima el valor con 
    // exactamente una posición decimal.
    
    printf("La suma es: %d\n", suma); // <--- MODIFICA ESTA LÍNEA

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (suma == 15.5f) {
        return 0;
    }
    
    return 1;
}
