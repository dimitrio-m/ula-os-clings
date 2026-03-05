#include <stdio.h>

int active_node = 0xAAAA;
int backup_node = 0xBBBB;

// INSTRUCCIÓN 1:
// Completa la firma de esta función y su cuerpo. 
// El objetivo es que esta rutina pueda modificar el destino de un puntero 
// que vive fuera de su scope (en el main), redirigiéndolo hacia la 
// dirección de memoria de 'backup_node'.
// RESTRICCIÓN: Tienes estrictamente prohibido usar la palabra reservada 'return'.

void failover_switch(int **arg) {
    
    // <--- ESCRIBE TU CÓDIGO AQUÍ ABAJO --->   
    *arg = &backup_node;
}

int main() {
    int *system_ptr = &active_node;

    // INSTRUCCIÓN 2:
    // Invoca la rutina 'failover_switch' pasando los argumentos necesarios 
    // para que 'system_ptr' sea redirigido al nodo de respaldo.
    
    // <--- ESCRIBE TU CÓDIGO AQUÍ ABAJO --->
    failover_switch(&system_ptr);
    

    // --- ZONA DE VALIDACIÓN (No modificar) ---
    if (system_ptr == &backup_node) {
        if (*system_ptr == 0xBBBB) {
            printf("✅ Correcto. Dominas la reasignación de direcciones mediante punteros dobles.\n");
            return 0;
        }
    }

    printf("❌ Fallo de conmutación. El puntero del sistema sigue apuntando al nodo colapsado o a la nada.\n");
    return 1;
}
