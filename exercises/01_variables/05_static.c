#include <stdio.h>

// Esta función simula un contador de visitas a un servidor
int contar_visitas() {
    // TODO: Cada vez que llamamos a esta función, la variable 'visitas'
    // se crea de nuevo en el Stack y se inicializa en 0.
    // Queremos que la variable RECUERDE su valor entre llamadas.
    // Pista: Agrega la palabra clave 'static' antes del tipo de dato.
    
    int visitas = 0; // <--- MODIFICA ESTA LÍNEA
    visitas++;
    return visitas;
}

int main() {
    printf("Visita 1: %d\n", contar_visitas());
    printf("Visita 2: %d\n", contar_visitas());
    printf("Visita 3: %d\n", contar_visitas());

    // Si funciona bien, la tercera visita debe devolver 3.
    if (contar_visitas() == 4) {
        printf("✅ ¡Correcto! La variable persiste en memoria.\n");
        return 0;
    }

    printf("❌ La variable está perdiendo la memoria (siempre vale 1).\n");
    return 1;
}
