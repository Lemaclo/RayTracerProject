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

using namespace std;

int main(){
	// Escena de prueba hardcodeada
	shared_ptr<sphere> s1 = make_shared<sphere>(0.5f, point3(0.0f,0.0f,-1.0f));
	shared_ptr<sphere> s2 = make_shared<sphere>(100.0f, point3(0, -100.5f, -1.0f));
	hittableList world(s1);
	world.add(s2);
	// Creamos una cámara
	camera cam;
	cam.aspect_ratio = 16.0f / 9.0f;
	cam.image_width = 400;
	cam.samples_per_pixel = 100;
	// Renderizamos la imagen de la escena
	cam.render(world);
	return 0;
}
