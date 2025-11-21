# ifndef COLOR
# define COLOR

# define color vec3
# include <cmath>
# include "vec3Class.hpp"
# include "intervalClass.hpp"

// Función auxiliar para escribir el color de un pixel en el formato R G B (enteros)
void write_color(ostream &o, const color& pixel_color);
// No sabía, pero al parecer los visores de imagen esperan que los colores estén en 
// una escala no lineal.
inline double gamma_correction(double linear_component){
	if(linear_component > 0) return std::sqrt(linear_component);
	return 0;
}

# endif

