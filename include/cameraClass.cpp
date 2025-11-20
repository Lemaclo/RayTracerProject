# include "cameraClass.hpp"

camera::camera(){}

void camera::init(){
	image_height = max(1, int(image_width / aspect_ratio));
	double focal_length = 1.0f; // Distancia de la camara al plano de vista
	double viewport_height = 2.0f;  // Dimensiones del plano de vista
	double viewport_width = viewport_height * ((double)image_width / image_height);
	// Vectores auxiliares para trabajar con el plano de vista
	vec3 viewport_horizontal = vec3(viewport_width,0.0f,0.0f); // (0,0) -->
	vec3 viewport_vertical = vec3(0.0f,-viewport_height,0.0f); // |
	// Distancia entre pixeles en R3
	pixel_horizontal_delta = viewport_horizontal / image_width;
	pixel_vertical_delta = viewport_vertical / image_height;
	// Coordenadas de la esquina superior izquierda del viewport
	point3 viewport_origin = camera_center - vec3(0.0f,0.0f,focal_length)
		- 0.5 * viewport_horizontal - 0.5 * viewport_vertical;
	pixel_origin = viewport_origin + 0.5*pixel_horizontal_delta + 0.5*pixel_vertical_delta;
}

// Función principal del proyecto. Lanza un rayo, y devuelve un color
color camera::rayTrace(const ray& r,  const hittable& world){
	hit_record rec;
	if(world.hit(r,interval(0,infinity),rec)){
		return 0.5*(rec.normal + color(1.0f,1.0f,1.0f));
	}
	// Fondo (si no hubo colisión)
	double h = 0.5 * (r.direction.y() + 1.0f); // Entre 0 y 1, pues direction esta normalizado
	return (1.0f - h)*color(0.63f, 0.28f, 0.92f) + h*color(0.96f, 0.76f, 0.43f);
}

// Lanza un rayo por pixel, y crea una imagen
void camera::render(const hittable& world){
	init();
	// Encabezado del formato PPM de imagen
	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
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
}
