#include <stdio.h>

void say_hello() {
    printf("¡Hola desde la función!\n");
}

void execute_task(void (*task_func)()) {
    // TODO: Ejecuta la función que recibiste como parámetro.
    // Solo tienes que llamarla.
    
    // ... tu código aquí ...
}

int main() {
    // Pasamos la dirección de 'say_hello' a 'execute_task'
    // TODO: Descomenta y arregla la llamada dentro de execute_task
    
    execute_task(say_hello); 
    
    // Si el programa no explota y compila, asumimos éxito para este ejercicio básico
    return 0;
}
