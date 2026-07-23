# Funcionamiento general del motor gráfico

# NOTA: Esto sólo son notas de como debería de funcionar desde la perspectiva de un usuario, no es un documento que pretenda
# ser una documentación fija del módulo del motor gráfico en si mismo.

Este documento contiene las historias de usuario relacionadas al funcionamiento general y común que debe tener el motor gráfico para que cumpla con los
requerimientos mínimos y funcionales para el proyecto.

Con este motor el usuario va a gestionar todo el apartado grafico del programa, el usuario debe poder:

1. Crear ventanas.
	- Definir el titulo de la ventana.
	- Definir las dimensiones de la ventana.
	- Por defecto las ventanas siempre serán flotantes.
2. Destruir las ventanas.
	- Liberar los recursos utilizados de la ventana.
3. Crear rasters para framebuffers.
	- Por defecto siempre se crearan rasters de pixeles en formato RGBA8888.
	- También se debe proveer el soporte para crear un depthbuffer que funcione en conjunto con el framebuffer y las utilidades del raster.
	- El depthbuffer debe almacenar la profundidad de los pixeles en forma de flotantes de 32 bits.
4. Establecer el raster que se utilizará por defecto en la máquina de estados.
5. Pintar pixeles libremente en el raster.
	- Poder pintar pixeles condicionados por su valor de profundidad para el depthbuffer.
6. Obtener el valor RGBA8888 de un pixel a través de sus coordenadas.
7. Obtener el valor de su profundidad (valor del pixel en el depthbuffer) a través de sus coordenadas.
8. Rellenar todo el raster de un solo valor RGBA8888.
	- Rellenar todo el depthbuffer con un solo valor.

---

# Historias

# El repositorio y la arquitectura

El usuario descarga el repositorio que contiene el motor gráfico, dicho motor gráfico se encuentra dentro del repositorio en forma de módulo ya que pertenece a una arquitectura tipo framework
que separa las responsabilidades de cada sistema en modulos, en dicho repositorio el usuario cuenta principalmente con el módulo de utilidades compartidas la cual es una capa que constituye
de elementos elaborados utilizando meramente el estándar ISO C lo cual dota de dichos elementos la capacidad de ser compatibles con cualquier programa en los principales sistemas operativos
los cuales se tuvo previsto el soporte (Windows y Linux) entre este sistema de utilidades podemos destacar principalmente las de gestión de colores para algoritmos de mezclas de colores y
gestión de colores en diferentes formatos (principalmente RGBX8888 y RGBA8888), el usuario cuenta también con utilidades para calculos matemáticos con matrices y vectores, también cuenta
con utilidades para el calculo y gestión de los deltatimes y calculo de FPS que puede utilizar en sus programas. Además se encontrará con otros 2 módulos los cuales son el módulo
del motor de físicas y el módulo del motor gráfico (el cuál se trata en este documento).

# Fase 1 - Descarga y Compilación

**Descarga:**

El usuario para utilizar el motor gráfico comienza primero descargando el repositorio del motor desde github, no se descargan librerías .so, .a o .dll sólo se descarga el repositorio
que contiene todo el código fuente del motor gráfico distribuido en ficheros de código fuente .c y ficheros de cabecera .h, el motor gráfico ya contiene el Makefile que contiene
la configuración necesaria para compilar el motor gráfico a ficheros de código objeto .o, dichos ficheros de código objeto serán los que el usuario utilizará para enlazar el módulo de motor gráfico
a sus propios programas.

**Compilación:**

Se debe de tener instalado:

1. gcc14 o una versión equivalente que soporte las características del estándar ISO C 23.
2. Make para utilizar el sistema de compilación del proyecto.
3. SDL2 para el uso del motor gráfico ya que su backend se basa principalmente en este.

Para compilar un programa utilizando el módulo del motor gráfico el usuario se puede basar en alguno de los programas de prueba que se encuentran en el directorio programs 
que se encuentra en la raíz del proyecto, en dichos ejemplos de prueba bien documentados el usuario podra basarse en su estructura y configuración de Makefile para crear los suyos propios.


# Partes del motor gráfico

- Sistema de gestión de ventanas
	[ ] Crear ventanas
	[ ] Modificar ventanas en tiempo real
	[ ] Destruir ventanas




















