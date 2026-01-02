#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para INT_MAX

int main() {
    int precio_unitario = 1000;
    int saldo_usuario = 5000;
    
    // El atacante intenta comprar una cantidad gigante para causar overflow
    // Si int es 32-bits, INT_MAX es aprox 2 mil millones.
    int cantidad_deseada = 3000000; // 3 millones

    // ---------------------------------------------------------
    // CÓDIGO VULNERABLE
    // Aquí ocurre el overflow. 1000 * 3,000,000 = 3,000,000,000
    // Eso es mayor que INT_MAX (2,147,483,647), así que da la vuelta (wrap around)
    // y se convierte en un número negativo o muy pequeño.
    
    int costo_total = precio_unitario * cantidad_deseada;
    
    // TAREA: Antes de multiplicar, verifica si habrá overflow.
    // if (cantidad_deseada > INT_MAX / precio_unitario) ...
    
    // ---------------------------------------------------------

    printf("Intentando comprar %d unidades.\n", cantidad_deseada);
    printf("Costo calculado: %d\n", costo_total);

    if (costo_total < 0) {
        printf("❌ FALLO: Overflow detectado. El costo salió negativo.\n");
        return 1;
    }

    if (costo_total > saldo_usuario) {
        printf("✅ Seguro. El costo real excede el saldo, la compra se rechaza.\n");
        return 0; // CORRECTO: El sistema detectó que es muy caro
    } else {
        printf("❌ HACKEADO: Compraste millones de items por casi nada.\n");
        return 1;
    }
}
