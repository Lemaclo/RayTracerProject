# ifndef COLOR
# define COLOR

# include <iostream>
# include "vec3Class.hpp"
# define color vec3

using namespace std;

// Función auxiliar para escribir el color de un pixel en el formato R G B (enteros)
void write_color(ostream &o, const color& pixel_color);

# endif

