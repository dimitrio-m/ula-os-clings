#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p1 = {10, 20};
    Point *ptr = &p1;

    // TODO: Modifica 'x' usando el PUNTERO 'ptr', no la variable 'p1'.
    // Intenta usar el operador flecha (->).
    // Queremos que x pase de 10 a 100.

    if (p1.x == 100) {
        printf("✅ Usaste la flecha correctamente.\n");
        return 0;
    }
    
    return 1;
}
