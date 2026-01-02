#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t parking;

void* coche(void* arg) {
    int id = *(int*)arg;
    
    // TAREA: Intenta entrar al parking. (Resta 1 al semáforo).
    // Si es 0, se bloquea y espera.
    // sem_wait(&parking);
    
    printf("Coche %d: Entrando...\n", id);
    sleep(1); // Ocupando el espacio
    printf("Coche %d: Saliendo...\n", id);
    
    // TAREA: Libera el espacio. (Suma 1 al semáforo).
    // sem_post(&parking);
    
    return NULL;
}

int main() {
    // Inicializamos semáforo con 2 espacios
    sem_init(&parking, 0, 2);

    pthread_t t[5];
    int ids[5] = {1,2,3,4,5};

    for(int i=0; i<5; i++) pthread_create(&t[i], NULL, coche, &ids[i]);
    for(int i=0; i<5; i++) pthread_join(t[i], NULL);

    sem_destroy(&parking);
    
    // Este ejercicio es visual. Si ven que entran de 2 en 2, está bien.
    // El script lo pasará si compila y corre.
    return 0;
}
