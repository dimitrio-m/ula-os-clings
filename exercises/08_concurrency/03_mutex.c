#include <stdio.h>
#include <pthread.h>

int saldo = 1000;
pthread_mutex_t candado; // Declaramos el mutex

void* cajero_automatico(void* arg) {
    // TAREA: Bloquea el acceso antes de tocar el saldo.
    // pthread_mutex_lock(&candado);
    
    int dinero = saldo;
    dinero = dinero + 100; // Simulamos operación lenta
    saldo = dinero;
    
    // TAREA: Desbloquea al terminar.
    // pthread_mutex_unlock(&candado);
    
    return NULL;
}

int main() {
    // Inicializar el mutex
    pthread_mutex_init(&candado, NULL);

    pthread_t t1, t2, t3;
    
    // Tres cajeros sumando 100 cada uno. Saldo final debe ser 1300.
    pthread_create(&t1, NULL, cajero_automatico, NULL);
    pthread_create(&t2, NULL, cajero_automatico, NULL);
    pthread_create(&t3, NULL, cajero_automatico, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&candado);

    if (saldo == 1300) {
        printf("✅ Saldo correcto. El Mutex funcionó.\n");
        return 0;
    }
    printf("❌ Error en el saldo: %d (Race Condition detectada)\n", saldo);
    return 1;
}
