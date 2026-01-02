#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
pthread_cond_t cond;
int pizza_lista = 0;

void* cocinero(void* arg) {
    sleep(1);
    pthread_mutex_lock(&lock);
    pizza_lista = 1;
    printf("Cocinero: ¡Pizza lista! Enviando señal...\n");
    
    // TAREA: Despierta al repartidor.
    // pthread_cond_signal(&cond);
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* repartidor(void* arg) {
    pthread_mutex_lock(&lock);
    
    // TAREA: Mientras la pizza no esté lista, ESPERA.
    // pthread_cond_wait(&cond, &lock);
    
    // Si no usas wait, el repartidor revisará antes de tiempo y se irá sin pizza.
    if (pizza_lista == 0) {
        printf("Repartidor: ¿No hay pizza? Me voy. (FALLO)\n");
    } else {
        printf("Repartidor: ¡Pizza recibida! (ÉXITO)\n");
    }
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, repartidor, NULL); // Repartidor llega primero
    pthread_create(&t2, NULL, cocinero, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    if (pizza_lista == 1) return 0;
    return 1;
}
