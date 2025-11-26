# Proyecto Ray Tracer
### Luis Emilio Martínez Capetillo, Martes 25 de Noviembre del 2025
### Gráficas por Computadora
-------------------------------------

Implementé un Ray Tracer en C++. Tal y como vimos en clase, la idea básica es lanzar rayos desde el punto de 
vista de la cámara para colorear los pixeles de una imagen. 
Para las primitivas, implementé esferas, cubos, y triángulos. Para el modelo de iluminación, usé
el modelo de Phong (con rayos de sombra, y adaptado para sólo aplicar iluminación difusa y especular a 
los puntos que ven una fuente de luz). Tengo dos tipos de materiales: Metálicos (reflejantes) y Lambertianos
(opacos). La cámara es altamente configurable y móvil (se puede especificar el punto donde se encuentra,
el punto al que se ve, y el *field of view*). Por otro lado, el Ray Tracer puede renderizar escenas de 
archivos, usando tres archivos de configuración para la imagen a generar. 
El archivo `cameraConfig.txt` controla parámetros como la posición de la 
cámara, el *field of view*, las muestras (rayos lanzados) por pixel, y la resolución. El archivo 
`materials.txt` detalla las propiedades de los materiales que se usarán en la escena, como su color,
sus coeficientes de iluminación del modelo de Phong, y la reflectancia.
Por último, el archivo `escena.txt` configura las primitivas de la escena, con sus respectivos parámetros 
(dependiendo de si son esferas, cubos, o triángulos), y su material. El mismo archivo detalla las
fuentes de luz de la escena y sus propiedades.
El formato de los archivos está explicado con detalle `config_guide.md`.
Como funcionalidades adicionales, se usa *supersampling* (para *anti-aliasing* e iluminación más realista)
, y se implementaron materiales reflejantes.
Sin embargo, no implementé transformaciones afines ni volúmenes englobantes.

Con mucha ayuda de [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html).
