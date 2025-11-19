# include <iostream>
# include "include/vec3Class.hpp"

using namespace std;

int main(){
	// Dimensiones
	int image_width = 256, image_height = 256;
	// Vamos a usar el formato PPM de imagen. 
	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	// Hacemos un gradiente sencillo
	for(int i=0;i<image_height;i++){
		// Indicador de progreso simple.
		clog << "Trabajando en la fila " << i << " de " << image_height << "...\n" << flush;
		for(int j=0;j<image_width;j++){
			// Intensidades reales entre 0 y 1
			vec3 color((double)j / (double) image_width, 0.0f, (double)i / (double) image_height);
			color *= 255.999;
			// Escribimos al archivo
			cout << int(color.x()) << ' ' << int(color.y()) << ' ' << int(color.z()) << '\n';
		}
	}
	clog << "Render completado\n";
	return 0;
}
