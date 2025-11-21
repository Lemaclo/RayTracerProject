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

using namespace std;

int main(){
	// Escena de prueba hardcodeada
	shared_ptr<material> m1 = make_shared<metal>(color(0.3f,0.3f,0.3f), 0.5);
	shared_ptr<material> m2 = make_shared<lambertian>(color(0.1f,0.8f,0.3f), 0.1);
	shared_ptr<material> m3 = make_shared<lambertian>(color(0.8f,0.1f,0.2f), 0.2);
	shared_ptr<sphere> s1 = make_shared<sphere>(0.5f, point3(0.0f,0.0f,-1.0f), m1);
	shared_ptr<sphere> s2 = make_shared<sphere>(100.0f, point3(0, -100.5f, -1.0f), m2);
	shared_ptr<sphere> s3 = make_shared<sphere>(0.3f, point3(1.0f, 0.5f, -1.0f), m3);
	hittableList world(s1);
	world.add(s2);
	world.add(s3);
	// Creamos una cámara
	camera cam;
	cam.aspect_ratio = 16.0f / 9.0f;
	cam.image_width = 400;
	cam.samples_per_pixel = 100;
	cam.max_depth = 50;
	// Renderizamos la imagen de la escena
	cam.render(world);
	return 0;
}
