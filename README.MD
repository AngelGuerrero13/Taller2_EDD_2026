 # MP3 Reproductor de Música

Angel Guerrero
Diego Godoy
Felipe Argomedo

MP3 es un reproductor de música de consola desarrollado en C++ como parte del Taller 2 de la asignatura Estructuras de Datos. El programa permite cargar un catálogo de canciones desde un archivo de texto, gestionar una lista de reproducción y controlar la reproducción mediante comandos de teclado. El estado del reproductor se guarda automáticamente en un archivo de configuración al realizar cualquier acción.


Para la compilación y ejecución de MP3, se tiene que hacer doble click en el archivo compilar.bat en el explorador de windows/linux/mac.
El script compila todos los archivos fuente y ejecuta el programa automáticamente si la compilación es exitosa.

 ## Diagrama de Clases

 ## Archivos necesarios:
Antes de ejecutar asegúrate de tener en la carpeta nucleo:
music_source.txt — listado de canciones

 ## Funcionalidades del programa:
| Tecla |                                 Acción                                |
|-------|-----------------------------------------------------------------------|
| `W` | Reproducir / Pausar la canción actual                                   |
| `Q` | Retroceder a la canción anterior                                        |
| `E` | Avanzar a la canción siguiente                                          |
| `S` | Activar / Desactivar modo aleatorio                                     |
| `R` | Cambiar modo de repetición (Desactivado → Repetir una → Repetir todas)  |
| `A` | Ver lista de reproducción actual                                        |
| `L` | Ver catálogo completo                                                   |
| `X` | Guardar estado y salir del programa                                     |


 ## Para este proyecto se utilizo:

- Lenguaje: C++14
- Compilador: GNU GCC (MinGW)