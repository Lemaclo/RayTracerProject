# include "colorFunctions.hpp"

void write_color(ostream &o, const color& pixel_color){
	// Valores reales entre 0 y 1
	double r = pixel_color.x();
	double g = pixel_color.y();
	double b = pixel_color.z();
	// Llevamos los colores al espacio no lineal
	r = gamma_correction(r);
	g = gamma_correction(g);
	b = gamma_correction(b);
	// Valores enteros entre 0 y 255
	const interval intensity(0.0f, 0.9999f);
	int R = int(256 * intensity.clamp(r));
	int G = int(256 * intensity.clamp(g));
	int B = int(256 * intensity.clamp(b));
	o << R << ' ' << G << ' ' << B << '\n';
}
