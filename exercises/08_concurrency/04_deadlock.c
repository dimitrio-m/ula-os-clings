#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;

void* hilo_A(void* arg) {
    // A toma el 1 y luego quiere el 2
    pthread_mutex_lock(&lock1);
    sleep(1); // Forzamos el deadlock dando tiempo al otro hilo
    pthread_mutex_lock(&lock2);
    
    printf("Hilo A: Tengo ambos.\n");
    
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

void* hilo_B(void* arg) {
    // B toma el 2 y luego quiere el 1 (ORDEN INVERSO = PELIGRO)
    
    // TAREA: Cambia el orden aquí para que sea IGUAL al hilo A.
    // Primero lock1, luego lock2.
    
    pthread_mutex_lock(&lock2); // <--- CAMBIA ESTO
    sleep(1);
    pthread_mutex_lock(&lock1); // <--- Y ESTO
    
    printf("Hilo B: Tengo ambos.\n");
    
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return NULL;
}

int main() {
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, hilo_A, NULL);
    pthread_create(&t2, NULL, hilo_B, NULL); // Si hay deadlock, esto se cuelga aquí

    // Usamos timedjoin para no colgar el autograder si el estudiante falla
    // (En un sistema real sería pthread_join normal)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("✅ Si llegaste aquí, evitaste el Deadlock.\n");
    return 0;
}
