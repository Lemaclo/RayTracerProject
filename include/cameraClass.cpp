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
color camera::rayTrace(const ray& r,  const hittableList& world, int depth){
	if(depth <= 0) return color(0.0f,0.0f,0.0f);
	hit_record rec;
	if(world.hit(r,interval(0.001,infinity),rec)){
		// PRUEBA: LUZ
		double ka = rec.mat->ambient_coefficient;
		color radiance = ka * world.ambient_light;
		for(light l : world.light_sources){
			hit_record shadow_rec;
			vec3 dir = l.location - rec.p;
			double t_light = dir.norm();
			vec3 light_dir = dir / t_light;
			ray shadow_ray(rec.p, light_dir);
			if(!world.hit(shadow_ray,interval(0.001f,t_light),shadow_rec)){
				radiance += phong_ilumination(rec, r, shadow_ray, l, world);
			}
		}
		ray reflection;
		if(rec.mat->scatter(r,rec,reflection))
			radiance += rec.mat->reflectance * rayTrace(reflection,world, depth-1); 
		return radiance * rec.mat->col;
		// TODO: Refraction rayy
		//double ref_coefficient = rec.mat->ref;
	}
	// Fondo (si no hubo colisión)
	return color(0.01,0.01,0.01);
	//double h = 0.5 * (r.direction.y() + 1.0f); // Entre 0 y 1, pues direction esta normalizado
	//return (1.0f - h)*color(0.63f, 0.28f, 0.92f) + h*color(0.96f, 0.76f, 0.43f);
}

// Lanza un rayo por pixel, y crea una imagen
void camera::render(const hittableList& world){
	init();
	// Encabezado del formato PPM de imagen
	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for(int i=0;i<image_height;i++){
		// Indicador de progreso simple.
		clog << "Trabajando en la fila " << i << " de " << image_height << "...\n" << flush;
		for(int j=0;j<image_width;j++){
			color pixel_color = color(0.0f,0.0f,0.0f);
			// Lanzamos varios rayos por pixel, y tomamos el promedio
			for(int sample=0;sample<samples_per_pixel;sample++){
				ray r = get_ray(i,j);
				pixel_color += rayTrace(r,world,max_depth);
			}
			pixel_color /= (double)samples_per_pixel;
			// Y escribimos el color al archivo.
			write_color(cout, pixel_color);
		}
	}
	clog << "Render completado\n";
}

ray camera::get_ray(int i, int j){
	vec3 offset = sample_square();
	// Primero, determinamos la ubicación del rayo, modificando ligeramente la ubicación del pixel
	vec3 pixel_sample = pixel_origin + ((i+offset.y())*pixel_vertical_delta) + 
		((j+offset.x())*pixel_horizontal_delta);
	// Luego, creamos un rayo desde el ojo del espectador hacia dicho pixel
	vec3 ray_direction = normalize(pixel_sample - camera_center);
	return ray(camera_center, ray_direction);
}

vec3 camera::sample_square() const {
	return vec3(random_double() - 0.5f, random_double() - 0.5f, 0);
}

color camera::phong_ilumination(hit_record &rec, const ray& camera_ray, const ray& shadow_ray, light l,
		const hittableList& world){
	double kd = rec.mat->diffuse_coefficient;
	double ks = rec.mat->specular_coefficient;
	double ddot = dot(shadow_ray.direction, rec.normal);
	color diffuse = color(0,0,0);
	color specular = color(0,0,0);
	if(ddot > 0.0f){
		diffuse = kd * ddot * l.diffuse_component;
	}
	vec3 r = reflect(shadow_ray.direction, rec.normal);
	double sdot = dot(r, camera_ray.direction); // alpha pow
	if(sdot > 0){
		sdot = pow(sdot, rec.mat->specular_exponent);
		specular = ks * sdot * l.specular_component;
	}
	return diffuse + specular;
	
}
