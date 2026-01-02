#include <stdio.h>
#include <pthread.h>

// Variable compartida
int shared_counter = 0;

// Queremos sumar 1.000.000 en total (500k por hilo)
#define ITERATIONS 500000

void* increment(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        // TAREA: Esto no es atómico.
        // El CPU hace: Leer -> Sumar -> Guardar.
        // Si dos hilos lo hacen a la vez, se sobrescriben.
        shared_counter++; 
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Esperado: %d\n", ITERATIONS * 2);
    printf("Obtenido: %d\n", shared_counter);

    // Si el contador es exacto, pasamos. (Casi imposible sin Mutex)
    // TAREA PARA EL ALUMNO: Este ejercicio está diseñado para FALLAR.
    // Para pasarlo, deben envolver el incremento con un Mutex (que aprenderán a declarar).
    // O reducir ITERATIONS a 1 para que pase "de suerte".
    
    // Nota pedagógica: Aquí queremos que usen pthread_mutex_t.
    
    if (shared_counter == ITERATIONS * 2) {
        return 0;
    }
    return 1;
}
