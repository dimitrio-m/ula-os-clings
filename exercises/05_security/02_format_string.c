#include <stdio.h>

int main() {
    // Imaginemos que esto viene de un formulario web
    char *input_usuario = "Hola %x %x %x"; 
    
    int secreto = 12345; // Dato sensible en el Stack

    printf("--- Output del Servidor ---\n");

    // ---------------------------------------------------------
    // CÓDIGO VULNERABLE
    // Nunca pases el input del usuario directamente como primer argumento.
    // Si el usuario pone "%x", printf imprimirá datos de la pila (el secreto).
    
    printf(input_usuario); // <--- CAMBIA ESTO
    printf("\n");

    // PISTA PARA ARREGLARLO:
    // Siempre usa un format string fijo: printf("%s", input_usuario);
    // ---------------------------------------------------------

    // EL TEST: (Simulado, ya que no podemos detectar el leak fácilmente en un script simple)
    // Para este ejercicio, asumimos que si usas "%s" explícitamente, está arreglado.
    // Vamos a forzar el fallo si detectamos que NO usaste un formato fijo.
    
    // (En un entorno real, usaríamos herramientas de análisis estático, 
    // aquí confiamos en que el estudiante aplicará la corrección lógica).
    
    printf("✅ Si cambiaste a printf(\"%%s\", ...), estás protegido.\n");
    return 0;
}
