# include "colorFunctions.hpp"

void write_color(ostream &o, const color& pixel_color){
	// Valores reales entre 0 y 1
	double r = pixel_color.x();
	double g = pixel_color.y();
	double b = pixel_color.z();
	// Valores enteros entre 0 y 255
	int R = int(r * 255.999f);
	int G = int(g * 255.999f);
	int B = int(b * 255.999f);
	o << R << ' ' << G << ' ' << B << '\n';
}
