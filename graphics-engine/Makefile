#####################################################################

# Creado por: jason-devcode
# Fecha de creación: 17-7-2026

# Este Makefile se utiliza para compilar cada uno de los modulos del motor.

# Este Makefile se encarga de compilar el modulo a ficheros de código objeto
# que serán enlazados al programa principal (a los main de cada programa en el directorio
# programs).

# NOTA: Los ficheros de código objeto linkeables tanto en GNU Linux y en Windows se generan
# como ficheros .o, de este modo evitamos posibles problemas de incompatibilidad de tipos
# de librerías estáticas y también se evitan los problemas de patrones factory para la adaptación
# de librerías de carga dinámica .so o .dll.

####################################################################
# Configuración customizable

# Enlazamos las librerías de SDL para el modulo del motor gráfico
# Usamos SDL2 para este caso
SDL_LIBS=$(shell pkg-config --cflags --libs sdl2)

OPTIMIZATION_FLAGS = -O3

CUSTOM_FLAGS = $(SDL_LIBS) $(OPTIMIZATION_FLAGS)

####################################################################
# Configuración fija (tener cuidado al mover).

# Directorio de salida de los ficheros de código objeto
OUTPUT_DIR = objs

# Obtenemos todos los ficheros de código fuente C bajo el directorio
# definido en src/
SRC_FILES = $(wildcard src/*.c)

# Resolvemos los nombres y rutas de los ficheros de código objeto
OBJ_FILES = $(patsubst src/%.c, $(OUTPUT_DIR)/%.o, $(SRC_FILES))

# Directorio de ficheros de cabecera
INCLUDE_DIR = include

# Compilador C, en este caso GNU C Compiler (gcc)
CC = gcc-14

# Librerias:
LIBS = -lm

# Estándar C: C23
CSTD = -std=c23

# Flags para aseguramiento de calidad del código C
QUALITY_CODE_FLAGS = -Wall -Wextra -Wpedantic -Wfatal-errors -Wconversion -Wshadow -Wundef -Wfloat-equal

# Centralizamos la resolución de flags de compilación
COMPILE_FLAGS = $(CSTD) $(QUALITY_CODE_FLAGS) $(LIBS) $(CUSTOM_FLAGS) -I $(INCLUDE_DIR)

####################################################################
# Resolución de valores

# Primero el makefile identifica en que sistema operativo nos encontramos
# ya sea Windows o sistemas GNU Linux que son los 2
# principales donde sistemas dónde se contempla alcance de soporte.
ifeq ($(OS),Windows_NT)
	# Configuraciones específicas para Windows
	RM = del /Q
else
	# Configuraciones específicas para Linux (o macOS)
	RM = rm -rf
endif

####################################################################

# Se definen las reglas puras (phony) que no dependen de
# ficheros de salida, esto para evitar posibles errores de ficheros ya
# existentes.
.PHONY: all build clean

# Regla para ejecutar la regla de build sin pasar directamente la palabra a make
all: build

# Regla phony para limpiar los ficheros ejecutables
clean:
	$(RM) $(OUTPUT_DIR)

# Se define la regla phony dependiente de los ficheros objetos de salida para lanzar
# la regla de compilación de los código objeto.
build: $(OUTPUT_DIR) $(OBJ_FILES)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(OUTPUT_DIR)/%.o: src/%.c
	$(CC) -c $^ $(COMPILE_FLAGS) -o $@
