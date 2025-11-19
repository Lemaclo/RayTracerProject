# include <iostream>

using namespace std;

int main(){
	// Dimensiones
	int image_width = 256, image_height = 256;
	// Vamos a usar el formato PPM de imagen. 
	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	// Hacemos un gradiente sencillo
	for(int i=0;i<image_height;i++){
		for(int j=0;j<image_width;j++){
			// Intensidades reales entre 0 y 1
			double r = (double)j / (double) image_width; // Incrementa horizontalmente
			double g = 0.0f;
			double b = (double)i / (double) image_height; // Incrementa verticalmente
			// Intensidades enteras, entre 0 y 255
			int R = int(255.99f * r);
			int G = int(255.99f * g);
			int B = int(255.99f * b);
			// Escribimos al archivo
			cout << R << ' ' << G << ' ' << B << '\n';
		}
	}
	return 0;
}
