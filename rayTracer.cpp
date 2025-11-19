# include <iostream>
# include <cmath>
# include "include/vec3Class.hpp"
# include "include/colorFunctions.hpp"
# include "include/rayClass.hpp"

using namespace std;

// Dada una esfera y un rayo, regresa el tiempo t de interseccion del rayo
// con la esfera, o -1 si no hay interseccion.
double hit_sphere(const point3& center, double radius, const ray &r){
	vec3 oc = center - r.origin;
	// Resuelve una cuadratica que sale de la ecuacion de la esfera
	double a = r.direction.norm2();
	double b = -2.0f * dot(r.direction, oc);
	double c = oc.norm2() - radius*radius;
	double discriminant = b*b - 4*a*c;
	if(discriminant < 0){
		return -1.0f;
	}
	// Hay dos tiempos de interseccion. El menor es el que corresponde al frente
	return (-b - sqrt(discriminant)) / (2.0f*a);
}

color rayTrace(const ray& r){
	double t = hit_sphere(point3(0.0f,0.0f,-1.0f), 0.5, r);
	// Si el rayo le pega a la esfera, el color que regresa depende del normal en ese punto
	if(t > 0.0f){
		vec3 N = normalize(r.at(t) - vec3(0.0f,0.0f,-1.0f));
		return 0.5*color(N.x() + 1.0f, N.y() + 1.0f, N.z() + 1.0f);
	}
	// Fondo
	double h = 0.5 * (r.direction.y() + 1.0f); // Entre 0 y 1, pues direction esta normalizado
	return (1.0f - h)*color(0.63f, 0.28f, 0.92f) + h*color(0.96f, 0.76f, 0.43f);
}

int main(){
	// Configuración de la imagen 
	double aspect_ratio = 16.0f / 9.0f;
	int image_width = 800;
	int image_height = max(1, int(image_width / aspect_ratio));
	// Configuración de la cámara
	// El rectángulo viewport representa la ubicación (en R3) de nuestra pantalla, con 
	// los pixeles que vamos a mostrar como pequeños cuadrados.
	double focal_length = 1.0f; // Distancia de la cámara al plano viewport
	double viewport_height = 2.0f;  // Dimensiones de la ventana
	double viewport_width = viewport_height * ((double)image_width / image_height);
	vec3 camera_center = vec3(0.0f,0.0f,0.0f);
	// Vectores auxiliares para determinar la posición (en R3) del pixel (i,j)
	vec3 viewport_horizontal = vec3(viewport_width,0.0f,0.0f); // (0,0) -->
	vec3 viewport_vertical = vec3(0.0f,-viewport_height,0.0f); // |
	// Distancias de pixel a pixel.
	vec3 pixel_horizontal_delta = viewport_horizontal / image_width;
	vec3 pixel_vertical_delta = viewport_vertical / image_height;
	// Coordenadas de la esquina superior izquierda del viewport
	point3 viewport_origin = camera_center - vec3(0.0f,0.0f,focal_length)
		- 0.5 * viewport_horizontal - 0.5 * viewport_vertical;
	point3 pixel_origin = viewport_origin + 0.5*pixel_horizontal_delta + 0.5*pixel_vertical_delta;
	
	// Encabezado del formato PPM de imagen
	vec3 v(1.0f,2.0f,-3.0f);
	clog << "Prueba:\n" <<
		v.norm() << '\n' <<
		v.norm2() << '\n' <<
		normalize(v) << '\n' <<
		normalize(v).norm() << '\n' <<
		normalize(v).norm2() << '\n';
	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	// Hacemos un gradiente sencillo
	for(int i=0;i<image_height;i++){
		// Indicador de progreso simple.
		clog << "Trabajando en la fila " << i << " de " << image_height << "...\n" << flush;
		for(int j=0;j<image_width;j++){
			// Primero, determinamos la ubicación del pixel (j,i)
			point3 pixel_center = pixel_origin + (i*pixel_vertical_delta) + (j*pixel_horizontal_delta);
			// Luego, creamos un rayo desde el ojo del espectador hacia dicho pixel
			vec3 ray_direction = normalize(pixel_center - camera_center);
			ray r(camera_center, ray_direction);
			// Calculamos el color de ese rayo (esto es lo más importante)
			color pixel_color = rayTrace(r);
			// Y escribimos el color al archivo.
			write_color(cout, pixel_color);
		}
	}
	clog << "Render completado\n";
	return 0;
}
