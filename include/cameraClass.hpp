# ifndef CAMERA
# define CAMERA

# include "hittableClass.hpp"
# include "hittableListClass.hpp"
# include "colorFunctions.hpp"
# include "utility.hpp"
# include "materialClass.hpp"
# include "lightClass.hpp"
# include <cmath>

using namespace std;

struct camera{
	double aspect_ratio = 1.0f; // Proporción de altura y ancho de la imagen
	int image_width = 100; // Ancho
	int image_height; // Alto
	int samples_per_pixel = 10; // Supersampling. Cuantos rayos tiramos por pixel.
	int max_depth = 10; // Máximo número de veces que un rayo rebota
	vec3 camera_center = point3(0.0f,0.0f,0.0f); // Punto de vista del mundo 
	// Vectores auxiliares para trabajar la posicion de los pixeles en la escena
	vec3 pixel_horizontal_delta;
	vec3 pixel_vertical_delta;
	point3 pixel_origin;
	camera();
	void init();
	// Función principal de todo esto: Lanza un rayo y devuelve un color.
	color rayTrace(const ray& r,  const hittableList& world, int depth); 
	// Lanza un rayo por pixel y crea una imagen
	void render(const hittableList& world);
	// Devuelve un rayo para el pixel i,j aleatorio en un cuadrado pequeño
	ray get_ray(int i, int j);
	// Auxiliar para obtener un vector aletorio en el cuadrado pequeño
	vec3 sample_square() const;
	// Modelo de iluminacion de phong
	color phong_ilumination(hit_record &rec, const ray& camera_ray, const ray& shadow_ray, light l, 
			const hittableList& world);
};

# endif
