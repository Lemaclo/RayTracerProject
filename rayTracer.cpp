# include "include/utility.hpp"

using namespace std;

color rayTrace(const ray& r, const hittable &world){
	hit_record rec;
	if(world.hit(r,interval(0,infinity),rec)){
		return 0.5*(rec.normal + color(1.0f,1.0f,1.0f));
	}
	// Fondo (si no hubo colisión)
	double h = 0.5 * (r.direction.y() + 1.0f); // Entre 0 y 1, pues direction esta normalizado
	return (1.0f - h)*color(0.63f, 0.28f, 0.92f) + h*color(0.96f, 0.76f, 0.43f);
}

int main(){
	// Configuración de la imagen 
	double aspect_ratio = 16.0f / 9.0f;
	int image_width = 400;
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
	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	// Escena de prueba
	shared_ptr<sphere> s1 = make_shared<sphere>(0.5f, point3(0.0f,0.0f,-1.0f));
	shared_ptr<sphere> s2 = make_shared<sphere>(100.0f, point3(0, -100.5f, -1.0f));
	hittableList world(s1);
	world.add(s2);
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
			color pixel_color = rayTrace(r, world);
			// Y escribimos el color al archivo.
			write_color(cout, pixel_color);
		}
	}
	clog << "Render completado\n";
	return 0;
}
