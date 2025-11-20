# ifndef CAMERA
# define CAMERA

# include "hittableClass.hpp"
# include "colorFunctions.hpp"

struct camera{
	double aspect_ratio = 1.0f; // Proporción de altura y ancho de la imagen
	int image_width = 100; // Ancho
	int image_height; // Alto
	vec3 camera_center = point3(0.0f,0.0f,0.0f); // Punto de vista del mundo 
	// Vectores auxiliares para trabajar la posicion de los pixeles en la escena
	vec3 pixel_horizontal_delta;
	vec3 pixel_vertical_delta;
	point3 pixel_origin;
	camera();
	void init();
	// Función principal de todo esto: Lanza un rayo y devuelve un color.
	color rayTrace(const ray& r,  const hittable& world); 
	// Lanza un rayo por pixel y crea una imagen
	void render(const hittable& world);

};

# endif
