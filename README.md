# 🦀 ISPSOP C-Lings: Prácticas en C

> **Materia:** Sistemas Operativos (ISPSOP)
> **Profesor:** Dimitrio Mandamadiotis

Bienvenido al **Dojo de Programación en C**.
Antes de construir servidores web o manipular procesos del Kernel, necesitas dominar la herramienta fundamental: el lenguaje C y la gestión de memoria.

Este repositorio no es un libro de texto. Es una serie de **pequeños desafíos rotos** que debes arreglar.

## 🎮 ¿Cómo funciona esto?

La metodología es simple: **Lee, Falla, Arregla, Repite.**

1. Cada ejercicio es un archivo `.c` que tiene un error (de compilación, de lógica o de memoria).
2. Tu trabajo es editar el archivo para que compile y pase las pruebas.
3. No pases al siguiente hasta que veas el mensaje verde: `✅ ¡PASASTE!`

## 🛠️ Requisitos Previos

Necesitas un entorno Linux/WSL con las herramientas básicas de compilación.

```bash
# En Ubuntu / Debian / WSL
sudo apt update
sudo apt install build-essential gcc

```

## 🚀 Guía de Inicio Rápido

1. **Clona este repositorio:**
```bash
git clone https://github.com/dimitrio-m/ula-os-clings
cd ula-os-clings

```


2. **Ejecuta tu primer ejercicio:**
Intentemos correr el primer ejercicio de la carpeta `00_intro`.
```bash
bash ./check.sh exercises/00_intro/01_welcome.c

```


3. **Observa el error:**
Probablemente verás un mensaje rojo o un error de compilación. ¡Eso es bueno! Lee lo que dice el compilador.
4. **Arregla el código:**
Abre el archivo en VS Code:
```bash
code exercises/00_intro/01_welcome.c

```


Busca los comentarios que dicen `// TODO` o `// FIX ME`. Arregla el código.
5. **Verifica de nuevo:**
Vuelve a correr el script:
```bash
bash ./check.sh exercises/00_intro/01_welcome.c

```


Si ves el mensaje verde, ¡felicidades! Pasa al siguiente archivo.

---

## 🗺️ Mapa de Ejercicios

Los ejercicios están ordenados por dificultad. No te saltes secciones.

(POR MEJORAR)

### 🐣 Nivel 1: Calentamiento

* `00_intro/`: Sintaxis básica, `main()`, y `printf`.
* `01_variables/`: Tipos de datos (`int`, `char`, `float`) y tamaños (`sizeof`).

### 💀 Nivel 2: La Zona de Peligro (Punteros)

* `02_pointers/`: Qué es una dirección de memoria (`&`) y qué es de-referenciar (`*`).
* `03_arrays/`: Aritmética de punteros y arrays. ¡Cuidado con salirte del índice!

### 🧠 Nivel 3: Gestión de Memoria (El núcleo de la materia)

* `04_memory/`: Stack vs Heap. Uso de `malloc` y `free`.
* `05_structs/`: Estructuras de datos personalizadas.

### 🧵 Nivel 4: Sistemas Operativos (Pre-Proyecto)

* `06_processes/`: Introducción a `fork()` (Clonación).
* `07_files/`: Leer y escribir archivos (`open`, `read`).

---

## 🤖 El Script Mágico (`check.sh`)

Este repositorio incluye un script de autoevaluación. Este script compila tu código usando banderas estrictas (`-Wall -Wextra`) y activa el **AddressSanitizer**.

**¿Qué significa esto?**
Si tu código compila pero tienes una "fuga de memoria" (no hiciste `free`) o intentas acceder a memoria que no te pertenece, el script te lo gritará en la cara con un error detallado.

> **Regla de Oro:** Si `check.sh` dice que está mal, está mal. Aunque "en tu máquina funcione".

---

## 🤝 Contribuciones

¿Encontraste un error en un ejercicio? ¿La explicación es confusa?
¡Envía un Pull Request arreglándolo! Mejorar este material cuenta como participación en clase.

---

*"Talk is cheap. Show me the code."* - Linus Torvalds


