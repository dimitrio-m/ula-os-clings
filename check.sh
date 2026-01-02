#!/bin/bash

# Colores para que se vea bonito en la terminal
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=========================================${NC}"
echo -e "${BLUE}       🤖 SISTEMAS OPERATIVOS - ULA      ${NC}"
echo -e "${BLUE}           Auto-Grader v1.0              ${NC}"
echo -e "${BLUE}=========================================${NC}"

# Verificar argumento
if [ -z "$1" ]; then
    echo -e "Uso: ./check.sh <ruta_del_ejercicio>"
    echo -e "Ejemplo: ./check.sh exercises/01_intro/hello.c"
    exit 1
fi

FILE=$1
BIN_NAME="temp_exercise"

# 1. Intentar Compilar
echo -e "🔨 Compilando ${FILE}..."
# Usamos flags estrictos + AddressSanitizer para atrapar errores de memoria
gcc -Wall -Wextra -fsanitize=address "$FILE" -o "$BIN_NAME"

if [ $? -ne 0 ]; then
    echo -e "${RED}❌ ERROR DE COMPILACIÓN${NC}"
    echo "Revisa la sintaxis o los tipos de datos."
    exit 1
fi

# 2. Ejecutar el binario
echo -e "🚀 Ejecutando..."
./"$BIN_NAME"

# Capturar el código de salida (return del main)
EXIT_CODE=$?

# Limpiar basura
rm "$BIN_NAME"

echo ""
echo "-----------------------------------------"

# 3. Evaluar resultado
if [ $EXIT_CODE -eq 0 ]; then
    echo -e "${GREEN}✅ ¡PASASTE! Ejercicio completado.${NC}"
    echo -e "Buen trabajo. Pasa al siguiente."
else
    echo -e "${RED}❌ FALLASTE. El programa retornó error.${NC}"
    echo -e "Pista: El main debe retornar 0 solo si la lógica es correcta."
    echo -e "Revisa los comentarios 'TODO' en el código."
fi
