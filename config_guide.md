## Camera Config

AspectRatioX  AspectRatioY
ImageWidth
SamplesPerPixel     MaxDepth(de un rayo)
FieldOfView (angles)
LookFrom (x,y,z)
LookAt
VectorUp (si no es (0,1,0) es como girar la camara)

-----------------------------------

## Material Config

Numero de Materiales
Tipo (0: lambertiano; 1 : metal)
R G B AmbientCoeff DiffuseCoeff SpecularCoeff SpecularExponent Reflectance Refractance(no se usa)

-----------------------------------

## Entity Config

Number of Entities
Tipo (0: esfera; 1: cubo, 2: triangulo)
- **Esfera:** Radio Centro (x,y,z)
- **Cubo:** Intervalo en x, y, z
- **Triángulo:** Punto a, b, c (3 coordenadas cada uno)
Material (índice según materiales.txt)

Luz ambiente (r g b; entre 0 y 1)
Color de fondo

Número de fuentes de luz
Posición (x,y,z) Intensidad difusa (r,g,b) Intensidad especular
