# include <iostream>
# include <cmath>
# include <limits>
# include <memory>
# include <cstdlib>

using namespace std;

# include "include/utility.hpp"
# include "include/colorFunctions.hpp"
# include "include/intervalClass.hpp"
# include "include/vec3Class.hpp"
# include "include/hittableClass.hpp"
# include "include/hittableListClass.hpp"
# include "include/sphereClass.hpp"
# include "include/rayClass.hpp"
# include "include/cameraClass.hpp"
# include "include/materialClass.hpp"
# include "include/lightClass.hpp"

int main(){
	// Materiales
	// ambient, diffuse, specular, specular_expo, reflectance, refractance
	shared_ptr<material> rubber = make_shared<lambertian>(color(1.0f,0.0f,0.0f),0.02,0.01,0.4,10,0.3, 0.0);
	shared_ptr<material> bronze = make_shared<metal>(color(0.9f,0.72f,0.2f),0.2125,0.714,0.4,25.6,0.01, 0.0);
	//shared_ptr<material> right = make_shared<metal>(color(0.8f,0.6f,0.2f), 0.1,0.4,0.2, 0.3, 0.0);
	// Escena de prueba hardcodeada
	hittableList world(make_shared<sphere>(100.0f, point3(0, -100.5f, -1.0f), bronze));
	world.add(make_shared<sphere>(0.5f, point3(0.0f,0.0f,-1.2f), rubber));
	//world.add(make_shared<sphere>(0.5f, point3(-1.0f,0.0f,-1.0f), left));
	//world.add(make_shared<sphere>(0.5f, point3(1.0f,0.0f,-1.0f), right));
	world.ambient_light = color(0.11,0.11,0.11);
	world.add_light_source(light(vec3(-1.0f, 10.0f, 0.0f), color(4.0,4.0,4.0), color(0.9,0.9,0.9)));
	//world.add_light_source(light(vec3(10.0f, 3.0f, 0.0f), color(0.0,0.9,0.0), color(0.9,0.9,0.9)));
	//world.add_light_source(light(vec3(0.0f, 0.0f, 5.0f), color(0.0,0.0,0.9), color(0.9,0.9,0.9)));
	// Creamos una cámara
	camera cam;
	cam.aspect_ratio = 16.0f / 9.0f;
	cam.image_width = 400;
	cam.samples_per_pixel = 50;
	cam.max_depth = 50;
	// Renderizamos la imagen de la escena
	cam.render(world);
	return 0;
}
