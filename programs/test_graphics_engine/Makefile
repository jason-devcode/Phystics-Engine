#####################################################################

# Creado por: jason-devcode
# Fecha de creación: 16-7-2026

# Este Makefile se utiliza para compilar de forma general
# los programas que encontramos en el directorio programs/

# Cada uno de estos genera un fichero con extensión .bin o .exe
# correspondiente al fichero ejecutable de dicho programa.

# NOTA: Para GNU Linux utilizamos la extensión .bin para que los ficheros
# ejecutables sean facilmente identificables en el .gitignore.

#####################################################################
# Configuración customizable

# Nombre del fichero ejecutable
# nota: sin extensión
TARGET = test_graphics_engine

# Indicamos la lista de modulos que queremos enlazar a nuestro programa
MODULES = graphics-engine physics-engine

# Directorio de salida donde se almacenará el fichero ejecutable
# nota: sin /
OUTPUT_DIR = binaries

CUSTOM_FLAGS = -O3

####################################################################
# Configuración fija (tener cuidado al mover).

# Directorio raíz relativo a este directorio donde se encontrarán los modulos
ROOT_DIR = ../..

# Directorio de los modulos
MODULES_DIR = $(ROOT_DIR)

# Se mapean las rutas de los directorios de cada modulo
MODULES_PATHS = $(foreach mod, $(MODULES), $(MODULES_DIR)/$(mod))

# Directorios de ficheros de cabecera de cada modulo
INCLUDES_PATHS = $(foreach mod, $(MODULES_PATH), -I$(mod)/include)

# Obtenemos todos los ficheros de código fuente C bajo el directorio
# definido en src/
SRC_FILES = $(wildcard src/*.c)

# Directorio de ficheros de cabecera
INCLUDE_DIR = include

# Compilador C, en este caso GNU C Compiler (gcc)
CC = gcc-14

# Librerias:
# SDL2
LIBS = $(shell pkg-config --cflags --libs sdl2)

# Estándar C: C23
CSTD = -std=c23

# Flags para aseguramiento de calidad del código C
QUALITY_CODE_FLAGS = -Wall -Wextra -Wpedantic -Wfatal-errors -Wconversion -Wshadow -Wundef -Wfloat-equal

# Centralizamos la resolución de flags de compilación
COMPILE_FLAGS = $(CSTD) $(QUALITY_CODE_FLAGS) $(LIBS) $(CUSTOM_FLAGS) -I $(INCLUDE_DIR) $(INCLUDES_PATHS)

####################################################################
# Resolución de valores

# Primero el makefile identifica en que sistema operativo nos encontramos
# ya sea Windows o sistemas GNU Linux que son los 2
# principales donde sistemas dónde se contempla alcance de soporte.
ifeq ($(OS),Windows_NT)
	# Configuraciones específicas para Windows
	RM = del /Q
	# Extensión del fichero ejecutable
    	EXE_EXT = exe
	# Comando de ejecución para windows
	RUN_CMD = $(OUTPUT_DIR)\$(TARGET).$(EXE_EXT)
else
	# Configuraciones específicas para Linux (o macOS)
	RM = rm -rf
	# Extensión del fichero ejecutable
	EXE_EXT = bin
	# Comando de ejecución para linux
	RUN_CMD = ./$(OUTPUT_DIR)/$(TARGET).$(EXE_EXT)
endif

# Se resuelve el nombre completo del ejecutable de salida
TARGET_OS = $(OUTPUT_DIR)/$(TARGET).$(EXE_EXT)

####################################################################

# Se definen las reglas puras (phony) que no dependen de
# ficheros de salida, esto para evitar posibles errores de ficheros ya
# existentes.
.PHONY: all build run clean compile_modules clean_submodules

# Regla phony general para compilar todo
all: build

# Regla phony para ejecutar el programa sin cambiar de directorio
run:
	$(RUN_CMD)

# Regla phony para limpiar los ficheros ejecutables
clean: clean_submodules
	$(RM) $(OUTPUT_DIR)

# Se define la regla phony dependiente del fichero ejecutable para lanzar
# la regla de compilación del fichero
build: compile_modules $(TARGET_OS)

# Regla para compilar los modulos
compile_modules:
	@echo "Compilando sub-modulos..."
	$(foreach mod, $(MODULES_PATHS), $(MAKE) --no-print-directory -C $(mod) build;)

# Regla para compilar el binario ejecutable
$(TARGET_OS): $(SRC_FILES)
	mkdir -p $(OUTPUT_DIR)
	$(CC) $^ $(COMPILE_FLAGS) `find $(MODULE_PATHS) -name '*.o'` -o $@

# Regla para limpiar los ficheros objeto de los submodulos
clean_submodules:
	@echo "Limpiando ficheros objeto de los submodulos..."
	$(foreach mod, $(MODULES_PATHS), $(MAKE) --no-print-directory -C $(mod) clean;)
