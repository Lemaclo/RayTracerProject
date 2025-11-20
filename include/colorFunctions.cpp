# include "colorFunctions.hpp"

void write_color(ostream &o, const color& pixel_color){
	// Valores reales entre 0 y 1
	double r = pixel_color.x();
	double g = pixel_color.y();
	double b = pixel_color.z();
	const interval intensity(0.0f, 0.9999f);
	// Valores enteros entre 0 y 255
	int R = int(256 * intensity.clamp(r));
	int G = int(256 * intensity.clamp(g));
	int B = int(256 * intensity.clamp(b));
	o << R << ' ' << G << ' ' << B << '\n';
}
