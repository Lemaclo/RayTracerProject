# ifndef COLOR
# define COLOR

# define color vec3
# include "vec3Class.hpp"

// Función auxiliar para escribir el color de un pixel en el formato R G B (enteros)
void write_color(ostream &o, const color& pixel_color);

# endif

