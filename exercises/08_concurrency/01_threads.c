#include <stdio.h>
#include <pthread.h>

// La función que correrá el hilo
void* worker(void* arg) {
    int *numero = (int*)arg;
    (*numero)++; // Incrementamos el valor
    return NULL;
}

int main() {
    pthread_t thread_id;
    int contador = 0;

    // TODO: Crea un hilo que ejecute 'worker' y le pase '&contador'.
    // pthread_create(&id, NULL, funcion, argumento);
    
    // ESCRIBE TU CÓDIGO AQUÍ:
    // pthread_create(...);

    // Esperamos a que el hilo termine
    // pthread_join(thread_id, NULL);

    if (contador == 1) {
        printf("✅ El hilo hizo su trabajo.\n");
        return 0;
    }
    
    printf("❌ El contador sigue en 0. ¿Creaste y esperaste al hilo?\n");
    return 1;
}
